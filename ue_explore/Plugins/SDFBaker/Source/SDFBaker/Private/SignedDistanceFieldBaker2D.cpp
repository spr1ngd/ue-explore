
#include "SignedDistanceFieldBaker2D.h"
#include "Engine/Texture2D.h"
#include "MathLibrary.h"
#include "DrawDebugHelpers.h"
#include "SignedDistanceFieldCommon.h"
#include "SignedDistanceFieldLibrary.h"
#include <time.h>
#include "Utils/CodeProfiler.h"

using namespace S;

void USignedDistanceFieldBaker2D::DrawAS(S::FBox_2DSDF* root, UWorld* world)
{
	FVector lt = FVector(root->min.X, root->max.Y, 0.0f);
	FVector rb = FVector(root->max.X, root->min.Y, 0.0f);
	DrawDebugLine(world, root->min, rb, FColor::Red, true, -1.0f, 0, 10.0f);
	DrawDebugLine(world, rb, root->max, FColor::Red, true, -1.0f, 0, 10.0f);
	DrawDebugLine(world, root->max, lt, FColor::Red, true, -1.0f, 0, 10.0f);
	DrawDebugLine(world, lt, root->min, FColor::Red, true, -1.0f, 0, 10.0f);
}

UTexture2D* USignedDistanceFieldBaker2D::Bake(TArray<FVector> points, FVector up)
{
	FCodeProfiler::BeginProfiler("Construct Acceleration Structure");
	//FQuadTree_2DSDF* bakeTree = new FQuadTree_2DSDF();
	//bakeTree->Construct(points);
	//DrawAS(bakeTree->root,this->GetWorld());
	bakedGrid = new FGrid_2DSDF(this->ExpandPercent);
	bakedGrid->Construct(points, 32, 32);
	FCodeProfiler::EndProfiler("Construct Acceleration Structure",false,true);

	DrawDebugSphere(this->GetWorld(), bakedGrid->min, 15.0f ,16, FColor::Green, true, -1.0f);
	DrawDebugSphere(this->GetWorld(), bakedGrid->max, 15.0f ,16, FColor::Green, true, -1.0f);
	for (int32 y = 0; y < 32; y++) {
		for (int32 x = 0; x < 32; x++) {
			FBox_2DSDF* cell = bakedGrid->GetCell(x, y);
			DrawAS(cell,this->GetWorld());
		}
	}

	// construct cell grid
	//FVector center, extent;
	//S::FMathLibrary::CalcAABB(points, center, extent);
	//extent *= (1 + ExpandPercent);
	//FVector boundMin = center - extent;
	//FVector boundMax = center + extent;
	// FVector boundSize = extent * 2;
	FVector boundMin = bakedGrid->min;
	FVector boundMax = bakedGrid->max;
	FVector boundSize = bakedGrid->size;
	FVector cellSize = FVector(
		boundSize.X / this->width,
		boundSize.Y / this->height,
		0.0f // bake signed distance field in x-y plane
	);

	FVector halfCellSize = cellSize * 0.5f;
	TArray<float> distance;
	float maxDist = FLT_MIN;
	TArray<FColor> sliceColors;

	// 使用grid划分,grid中存储多条交线的方向，使得可以快速判定一点在多边形内，或者多边形外
	// 求最短距离时可向周围的八个格子进行采样，判定计算最短距离
	for (int32 y = 0; y < this->height; y++)
	{
		float yOffset = y * cellSize.Y;
		for (int32 x = 0; x < this->width; x++)
		{
			float xOffset = x * cellSize.X;
			FVector sp = FVector(xOffset, yOffset, 0.0f);
			sp += (boundMin + halfCellSize);
			S::FCodeProfiler::BeginProfiler(TEXT("SDFPolygon"));
			// 改进前
			//float closestDistance = this->SDFPolygon2D(cellCenter, points);
			// 改进后
			float closestDistance = bakedGrid->ShortestDistance(sp);
			S::FCodeProfiler::EndProfiler(TEXT("SDFPolygon"), true, false);
			maxDist = FMath::Max(maxDist,FMath::Abs(closestDistance));
			distance.Add(closestDistance);
			//DrawDebugSphere(this->GetWorld(), sp, 20.0f, 10, FColor::Yellow, true, -1.0f);
		}
	}
	S::FCodeProfiler::EndProfiler(TEXT("SDFPolygon"), false, true);
	for (auto dist : distance)
	{
		// 这种形式会因为精度不够而产生效果误差
 		float d = dist / maxDist;
 		d = (d + 1.0f) / 2.0f;
		// float d = FMath::Sign(dist) * FMath::Clamp(FMath::Abs(dist), 0.0f, 1.0f);

//		d = d > 0.0f ? 1.0f : 0.0f;
		FLinearColor linearColor = FLinearColor(d, d, d);
		sliceColors.Add(linearColor.ToFColor(false));
	}
	UTexture2D* tex = USignedDistanceFieldLibrary::CreateTexture(this->exportDir, this->exportTexName, this->width, this->height, sliceColors);
	return tex;
}

void USignedDistanceFieldBaker2D::ShortestDistance(FVector sp, FVector& intersection)
{
	if (nullptr == bakedGrid)
		return;
	bakedGrid->ShortestDistance(sp, intersection);
}

// 看看是否需要提到函数库中
void USignedDistanceFieldBaker2D::ExtractFloatItem(float value, float& rChannel, float& gChannel, float& bChannel, float& aChannel)
{
	if (value == 0.0f) {
		rChannel = 0.0f;
		gChannel = 0.0f;
		bChannel = 0.0f;
		aChannel = 1.0f;
	}
	else
	{
		float a = FMath::Sign(value) >= 0 ? 1.0f : 0.0f;
		float valueWithoutSign = value * (FMath::Sign(value) >= 0 ? 1.0f : -1.0f);
		valueWithoutSign *= FMath::Pow(255.0f,3);

		float p1 = 255.0f;
		float p2 = p1 * p1;

		float r = FMath::FloorToInt(valueWithoutSign / p2);
		valueWithoutSign -= p2 * r;
		float g = FMath::FloorToInt(valueWithoutSign / p1);
		valueWithoutSign -= p1 * g;
		float b = FMath::Fmod(valueWithoutSign, p1);

		rChannel = r / 255.0f;
		gChannel = g / 255.0f;
		bChannel = b / 255.0f;
		aChannel = a;
	}
}


float USignedDistanceFieldBaker2D::SDFPolygon2D(FVector sp, TArray<FVector>& points)
{
	float dist = FLT_MAX;
	bool inPolygon = false;
	for (int32 i = 0; i < points.Num(); i++) 
	{
		FVector a = points[i];
		FVector b = points[i + 1 >= points.Num() ? 0 : i + 1];
		FVector edge = b - a;
		FVector ap = sp - a;
		FVector pab = ap - edge * FMath::Clamp(FVector::DotProduct(ap, edge) / FVector::DotProduct(edge, edge), 0.0f, 1.0f);
		float d = FMath::Sqrt(FVector::DotProduct(pab, pab));
		dist = FMath::Min(dist, d);
		//S::FCodeProfiler::BeginProfiler("InPolygonCheck");
		//// TODO: 此部分计算速度很慢
		//// TODO: 且此部分计算不能判定凹多边形
		//if (!inPolygon) {
		//	FVector c = points[i + 2 >= points.Num() ? 1 : i + 2];
		//	FVertex p0(points[0]);
		//	FVertex vb(b);
		//	FVertex vc(c);
		//	FTriangle tri(p0, vb, vc);
		//	inPolygon = tri.InTriangle(sp);
		//}
		//S::FCodeProfiler::EndProfiler("InPolygonCheck",true,false);
	}
	return inPolygon ? -dist : dist;
}
