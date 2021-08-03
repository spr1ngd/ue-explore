
#include "SignedDistanceFieldCommon.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"


#pragma region FVertex 

FVertex::FVertex(FVector pos)
{
	this->Position = pos;
	this->Normal = FVector(0, 1, 0);
}

FVertex::FVertex(FVector pos, FVector normal)
{
	this->Position = pos;
	this->Normal = normal;
}

#pragma endregion FVertex 

#pragma region FTriangleEdge

FTriangleEdge::FTriangleEdge(FVertex a, FVertex b)
{
	this->A = a;
	this->B = b;
	this->Edge = this->B.Position - this->A.Position;
	this->Direction = this->Edge.GetSafeNormal();
}

float FTriangleEdge::Distance(FVector p)
{
	FVector AP = (p - this->A.Position);
	float magnitude;
	FVector dir; 
	AP.ToDirectionAndLength(dir, magnitude);
	return FMath::Sin(FMath::Acos(FVector::DotProduct(dir, this->Direction))) * magnitude;
}

#pragma endregion FTriangleEdge

#pragma region FTriangle

FTriangle::FTriangle(FVertex a, FVertex b, FVertex c)
{
	this->A = a;
	this->B = b;
	this->C = c;

	this->AB = FTriangleEdge(this->A, this->B);
	this->BC = FTriangleEdge(this->B, this->C);
	this->CA = FTriangleEdge(this->C, this->A);
}

float FTriangle::ClosestDistance(FVector p)
{
	FVector intersectionPoint;
	return this->ClosestDistance(p, intersectionPoint);
}

float FTriangle::ClosestDistance(FVector p, FVector& outIntersectionPoint)
{
	float dist;

	// 1. 投影到三角形所在平面
	float projectionDist = 0.0f;
	FVector projectionPoint;
	this->Project(p, projectionDist, projectionPoint);
	if (projectionDist == FLT_MAX)
		return FLT_MAX;

	// ** 计算出p点在三边的垂直向量（指向p点）
	FVector AP = projectionPoint - this->A.Position;
	FVector BP = projectionPoint - this->B.Position;
	FVector CP = projectionPoint - this->C.Position;
	FVector PAB = AP - this->AB.Edge * FMath::Clamp(FVector::DotProduct(AP, this->AB.Edge) / FVector::DotProduct(this->AB.Edge, this->AB.Edge), 0.0f, 1.0f);
	FVector PBC = BP - this->BC.Edge * FMath::Clamp(FVector::DotProduct(BP, this->BC.Edge) / FVector::DotProduct(this->BC.Edge, this->BC.Edge), 0.0f, 1.0f);
	FVector PCA = CP - this->CA.Edge * FMath::Clamp(FVector::DotProduct(CP, this->CA.Edge) / FVector::DotProduct(this->CA.Edge, this->CA.Edge), 0.0f, 1.0f);

	float pab = FVector::DotProduct(PAB,PAB);
	float pbc = FVector::DotProduct(PBC,PBC);
	float pca = FVector::DotProduct(PCA,PCA);

	float min = FMath::Min3(pab,pbc,pca);
	if (this->InTriangle(projectionPoint)) {
		outIntersectionPoint = projectionPoint;
		dist =  FMath::Abs(projectionDist);
	}
	else{
		if (min == pab) {
			outIntersectionPoint = projectionPoint - PAB;
		}
		else if (min == pbc) {
			outIntersectionPoint = projectionPoint - PBC;
		}
		else if (min == pca) {
			outIntersectionPoint = projectionPoint - PCA;
		}
		dist = FVector::Distance(p,outIntersectionPoint);
	}
	dist *= FMath::Sign(FVector::DotProduct(this->CalcNormal(), (p - outIntersectionPoint).GetSafeNormal()));
	return dist;
}

float FTriangle::ProjectionDistance(FVector p)
{
	FVector faceNormal = this->CalcNormal();
	// TODO:
	if (faceNormal.X == 0.0f && faceNormal.Y == 0.0f && faceNormal.Z == 0.0f)
		return FLT_MAX;
	FVector APDir;
	float APMagnitude;
	(p - this->A.Position).ToDirectionAndLength(APDir,APMagnitude);
	float cosTheta = FVector::DotProduct(faceNormal, APDir);
	float distance = cosTheta * APMagnitude;
	return distance;
}

bool FTriangle::InTriangle(FVector p)
{
	FVector AP = (p - this->A.Position).GetSafeNormal();
	FVector BP = (p - this->B.Position).GetSafeNormal();
	FVector N0 = FVector::CrossProduct(this->AB.Direction,AP);
	FVector N1 = FVector::CrossProduct(this->BC.Direction,BP);

	// sign n01
	// float sign = UKismetMathLibrary::SignOfFloat(FVector::DotProduct(N0,N1));
	float sign = FMath::Sign<float>(FVector::DotProduct(N0, N1));
	if (sign < 0)
		return false;

	FVector CP = (p - this->C.Position).GetSafeNormal();
	FVector N2 = FVector::CrossProduct(this->CA.Direction, CP);
	sign = FMath::Sign<float>(FVector::DotProduct(N0, N2));
	return sign > 0.0f ? true : false;
}

void FTriangle::Project(FVector p, float& dist, FVector& subpoint)
{
	FVector faceNormal = this->CalcNormal();
	// TODO:
	if (faceNormal.X == 0.0f && faceNormal.Y == 0.0f && faceNormal.Z == 0.0f)
	{
		dist = FLT_MAX;
		return;
	}
	FVector APDir;
	float APMagnitude;
	(p - this->A.Position).ToDirectionAndLength(APDir, APMagnitude);
	float cosTheta = FVector::DotProduct(faceNormal, APDir);
	float distance = cosTheta * APMagnitude;

	dist = distance;
	subpoint = p - faceNormal * distance;
}

FVector FTriangle::CalcNormal()
{
	return -FVector::CrossProduct(this->AB.Direction, this->BC.Direction).GetSafeNormal();
}

#pragma endregion FTriangle
