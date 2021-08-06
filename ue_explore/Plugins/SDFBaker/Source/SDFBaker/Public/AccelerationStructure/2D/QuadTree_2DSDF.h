
// author : spr1ngd
// desc   : accelerate 2d sdf generation speed
// non-full quadtree

#pragma once
#include "CoreMinimal.h"
#include "AccelerationStructure/Common.h"

namespace S 
{
	class FQuadTree_2DSDF
	{
	public:
		FBox_2DSDF* root = nullptr;
		void Construct(TArray<FVector>& points);
		FBox_2DSDF* CalcBB(TArray<FVector>& points);
	private:

		void SplitBox(FBox_2DSDF* box);
	};
}