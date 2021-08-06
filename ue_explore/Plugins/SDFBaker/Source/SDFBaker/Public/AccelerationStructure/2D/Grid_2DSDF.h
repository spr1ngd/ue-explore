
// author : spr1ngd
// desc   : 

#pragma once
#include "CoreMinimal.h"
#include "AccelerationStructure/Common.h"
// 计算出aabb
// 划分为cell,cell需要分配id
// 求交cell中存在的line

namespace S 
{
	class FGrid_2DSDF
	{
	private:
		float expandPercent = 0.0f;
		int32 xSize, ySize;
		TArray<TArray<FBox_2DSDF*>> gridCells;
		void CalcBB(TArray<FVector>& points, FVector& min, FVector& max);
		void GetAroundCells(int32 xIndex, int32 yIndex, TArray<FBox_2DSDF*>& cells);
		void TryGetCell(int32 xIndex,int32 yIndex, TArray<FBox_2DSDF*>& cells);
		void Split(FBox_2DSDF* box,int32 curDepth,int32 maxDepth);
	public:
		FBox_2DSDF* root;
		FVector min, max, size, cellSize,halfCellSize;
		FGrid_2DSDF() {};
		FGrid_2DSDF(float inExpandPercent) 
		{
			this->expandPercent = inExpandPercent;
		}

		void Construct(TArray<FVector>& points,int32 xCell = 128,int32 yCell = 128);
		float ShortestDistance(FVector sp);
		float ShortestDistance(FVector sp,FVector& intersection);
		FBox_2DSDF* GetCell(int32 xIndex,int32 yIndex);
	};
}