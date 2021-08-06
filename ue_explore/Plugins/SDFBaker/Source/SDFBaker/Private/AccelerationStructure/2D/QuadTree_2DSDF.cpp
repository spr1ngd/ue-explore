
#include "AccelerationStructure/2D/QuadTree_2DSDF.h"
using namespace S;

#define MAX_LINES_INCELL 2
#define MIN_DIST 5.0f

void FQuadTree_2DSDF::Construct(TArray<FVector>& points)
{
	int32 pNum = points.Num();
	if (pNum < 2)
		return;

	// 我们假设点都是连续的
	// 先构造加速结构的边
	TArray<FEdge_2DSDF*> polygonEdges;
	for (int32 i = 0; i < pNum; i++) {
		FVector& start = points[i];
		FVector& end = points[i + 1 >= pNum ? 0 : i + 1];
		while (true){
			if (FVector::Dist(start, end) < MIN_DIST) {
				i++;
				end = points[i + 1 >= pNum ? 0 : i + 1];
			}
			break;
		}
		FEdge_2DSDF* edge = new FEdge_2DSDF(start,end);
		polygonEdges.Add(edge);
	}

	// 获取最大包围盒
	this->root = CalcBB(points);
	this->root->edges = polygonEdges;
	if( root->edges.Num() > MAX_LINES_INCELL )
		this->SplitBox(this->root);
}

void S::FQuadTree_2DSDF::SplitBox(FBox_2DSDF* box)
{
	box->Split();
	if (box->children.Num() <= 0)
		return;

	for (int32 i = 0; i < 4; i++) 
	{
		FBox_2DSDF* child = box->children[i];
		//if (!child->IsValid()) {
		//	continue;
		//}
		for (FEdge_2DSDF* edge : box->edges) {
			if (child->LineIntersection(edge)) {
				child->edges.Add(edge);
			}
		}
		if ( child->edges.Num() <= MAX_LINES_INCELL) {
			continue;
		}
		this->SplitBox(child);
	}
}

FBox_2DSDF* FQuadTree_2DSDF::CalcBB(TArray<FVector>& points)
{
	float minX = FLT_MAX, minY = FLT_MAX, minZ = FLT_MAX;
	float maxX = FLT_MIN, maxY = FLT_MIN, maxZ = FLT_MIN;
	for (int32 i = 0; i < points.Num(); i++) {
		FVector& point = points[i];
		minX = FMath::Min(point.X, minX);
		minY = FMath::Min(point.Y, minY);
		minZ = FMath::Min(point.Z, minZ);
		maxX = FMath::Max(point.X, maxX);
		maxY = FMath::Max(point.Y, maxY);
		maxZ = FMath::Max(point.Z, maxZ);
	}
	FVector boundMin = FVector(minX, minY, minZ);
	FVector boundMax = FVector(maxX, maxY, maxZ);
	return new FBox_2DSDF(boundMin,boundMax);
}