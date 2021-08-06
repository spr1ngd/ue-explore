
#include "AccelerationStructure/2D/Grid_2DSDF.h"
#include <Engine/World.h>
#include <DrawDebugHelpers.h>
#define MIN_DIST 5.0f

void S::FGrid_2DSDF::Construct(TArray<FVector>& points, int32 xCell /*= 128*/, int32 yCell /*= 128*/)
{
	int32 pNum = points.Num();
	if (pNum < 2)
		return;
	TArray<FEdge_2DSDF*> polygonEdges;
	for (int32 i = 0; i < pNum; i++) {
		FVector& start = points[i];
		FVector& end = points[i + 1 >= pNum ? 0 : i + 1];
		while (true) {
			if (FVector::Dist(start, end) < MIN_DIST) {
				i++;
				end = points[i + 1 >= pNum ? 0 : i + 1];
			}
			break;
		}
		FEdge_2DSDF* edge = new FEdge_2DSDF(start, end);
		polygonEdges.Add(edge);
	}

	this->CalcBB(points, this->min, this->max);
	this->size = max - min;
	this->cellSize = FVector(size.X / xCell, size.Y / yCell,0.0f);
	this->halfCellSize = this->cellSize * 0.5f;
	this->xSize = xCell;
	this->ySize = yCell;

	// 方案1：每个格子不好直接获取到距离最近的线段，以及是否在多边形的内外
	//for (int32 y = 0; y < yCell; y++) {
	//	float yOffset = cellSize.Y * y;
	//	TArray<FBox_2DSDF*> row;
	//	for (int32 x = 0; x < xCell; x++) {
	//		float xOffset = cellSize.X * x;
	//		FVector cellMin = min + FVector(xOffset, yOffset, 0.0f);
	//		FVector cellMax = cellMin + cellSize;
	//		FBox_2DSDF* cell = new FBox_2DSDF(cellMin, cellMax);
	//		
	//		for (int32 i = 0; i < polygonEdges.Num(); i++) {
	//			FEdge_2DSDF* edge = polygonEdges[i];
	//			if (cell->LineIntersection(edge)) {
	//				cell->edges.Add(edge);
	//			}
	//		}

	//		row.Add(cell);
	//	}
	//	this->gridCells.Add(row);
	//}

	// ...
	// [0,1] [1,1]
	// [0,0] [1,0] ...

	// 方案2：二分法，逐级下分，可以预分配距离最近的线段 ，最好分割次数是2的次幂（目前强制这样计算）
	for (int32 y = 0; y < yCell; y++) {
		TArray<FBox_2DSDF*> row;
		for (int32 x = 0; x < xCell; x++) {
			row.Add(nullptr);
		}
		this->gridCells.Add(row);
	}
	int32 maxDepth = FMath::FloorToInt(FMath::Log2(xCell));
	int32 curDepth = 0;
	this->root = new FBox_2DSDF(this->min,this->max);
	this->root->edges = polygonEdges;
	this->Split(root, curDepth, maxDepth);
}

void S::FGrid_2DSDF::Split(FBox_2DSDF* box, int32 curDepth, int32 maxDepth)
{
	if (curDepth >= maxDepth)
	{
		FVector offset = box->min - this->min + this->halfCellSize;
		int32 xIndex = FMath::FloorToInt(offset.X / this->cellSize.X);
		int32 yIndex = FMath::FloorToInt(offset.Y / this->cellSize.Y);
		this->gridCells[yIndex][xIndex] = box;
		return;
	}
	box->Split();
	for (int32 i = 0; i < 4; i++){
		FBox_2DSDF* child = box->children[i];
		for (FEdge_2DSDF* edge : box->edges) {
			if (child->LineIntersection(edge)) {
				child->edges.Add(edge);
			}
		}
		if (child->edges.Num() <= 0) {
			child->edges = child->parent->edges;
		}
		this->Split(child,curDepth + 1,maxDepth);
	}
}

float S::FGrid_2DSDF::ShortestDistance(FVector sp)
{
	FVector offset = sp - this->min;
	int32 xIndex = FMath::FloorToInt(offset.X / this->cellSize.X);
	int32 yIndex = FMath::FloorToInt(offset.Y / this->cellSize.Y);
	TArray<FBox_2DSDF*> cells;
	GetAroundCells(xIndex, yIndex, cells);
	TArray<FEdge_2DSDF*> lines;
	for (FBox_2DSDF* cell : cells) {
		for (FEdge_2DSDF* line : cell->edges) {
			lines.AddUnique(line);
		}
	}
	//lines = this->root->edges;
	float minDist = FLT_MAX;
	for (FEdge_2DSDF* edge : lines) {
		float dist = edge->ShortestDistance(sp);
		if (FMath::Abs(dist) < FMath::Abs(minDist)) {
			minDist = dist;
		}
	}
	return minDist;
}

float S::FGrid_2DSDF::ShortestDistance(FVector sp, FVector& intersection)
{
	FVector offset = sp - this->min;
	int32 xIndex = FMath::FloorToInt(offset.X / this->cellSize.X);
	int32 yIndex = FMath::FloorToInt(offset.Y / this->cellSize.Y);
	TArray<FBox_2DSDF*> cells;
	GetAroundCells(xIndex, yIndex, cells);
	TArray<FEdge_2DSDF*> lines;
	for (FBox_2DSDF* cell : cells) {
		for (FEdge_2DSDF* line : cell->edges) {
			lines.AddUnique(line);
		}
	}
	auto world = GWorld->GetGameInstance()->GetWorld();
	//lines = this->root->edges;
	float minDist = FLT_MAX;
	for (FEdge_2DSDF* edge : lines) {
		FVector p;
		float dist = edge->ShortestDistance(sp,p);
		if (FMath::Abs(dist) < FMath::Abs(minDist)) {
			minDist = dist;
			intersection = p;
		}

		DrawDebugLine(world, edge->start, edge->end, FColor::Cyan, false, 0.0f, 0, 20.0f);
	}
	return minDist;
}

S::FBox_2DSDF* S::FGrid_2DSDF::GetCell(int32 xIndex, int32 yIndex)
{
	if (xIndex < 0 || xIndex >= this->xSize)
		return nullptr;
	if (yIndex < 0 || yIndex >= this->ySize)
		return nullptr;
	return this->gridCells[yIndex][xIndex];
}

void S::FGrid_2DSDF::CalcBB(TArray<FVector>& points, FVector& outMin, FVector& outMax)
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
	FVector gridMin = FVector(minX, minY, 0.0f);
	FVector gridMax = FVector(maxX, maxY, 0.0f);
	FVector center = (gridMin + gridMax) * 0.5f;
	FVector extent = (gridMax - gridMin) * 0.5f;
	extent *= (1.0f + this->expandPercent);
	outMin = center - extent;
	outMax = center + extent;
}

void S::FGrid_2DSDF::GetAroundCells(int32 xIndex, int32 yIndex, TArray<FBox_2DSDF*>& cells)
{
	TryGetCell(xIndex - 1, yIndex + 1, cells); TryGetCell(xIndex + 0, yIndex + 1, cells); TryGetCell(xIndex + 1, yIndex + 1, cells);
	TryGetCell(xIndex - 1, yIndex + 0, cells); TryGetCell(xIndex + 0, yIndex + 0, cells); TryGetCell(xIndex + 1, yIndex + 0, cells);
	TryGetCell(xIndex - 1, yIndex - 1, cells); TryGetCell(xIndex + 0, yIndex - 1, cells); TryGetCell(xIndex + 1, yIndex - 1, cells);
}

void S::FGrid_2DSDF::TryGetCell(int32 xIndex, int32 yIndex, TArray<FBox_2DSDF*>& cells)
{
	if (xIndex < 0 || xIndex >= this->xSize)
		return;
	if (yIndex < 0 || yIndex >= this->ySize)
		return;
	cells.Add(this->gridCells[yIndex][xIndex]);
}