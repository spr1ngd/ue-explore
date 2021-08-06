
// author : spr1ngd
// desc   : axis-aligned bounding box
#pragma once
#include "CoreMinimal.h"

namespace S 
{
	struct FInt2_2DSDF 
	{
		int32 X;
		int32 Y;

		FInt2_2DSDF(int32 x,int32 y) 
		{
			X = x;
			Y = y;
		}
	};

	struct FEdge_2DSDF
	{
		FVector start;
		FVector end;
		FVector edge;
		FVector direction;
		float length;

		bool xParallel = false;
		bool yParallel = false;

		FEdge_2DSDF(FVector pStart, FVector pEnd);

		float ShortestDistance(FVector sp);
		float ShortestDistance(FVector sp,FVector& intersection);
	};

	struct FBox_2DSDF
	{
		FVector min;
		FVector max;
		FVector center;
		FVector extent;

		TArray<FEdge_2DSDF*> edges;
		FBox_2DSDF* parent = nullptr;
		TArray<FBox_2DSDF*> children;

		FBox_2DSDF(FVector pMin, FVector pMax)
		{
			min = pMin;
			max = pMax;
			center = (min + max) * 0.5f;
			extent = (max - min) * 0.5f;
		}

		bool IsValid();
		void Split();
		bool LineIntersection(FEdge_2DSDF* line);
		bool InsideBox(FVector point);
		bool OnBoxEdge(FVector point);
		float ShortestDistance(FVector sp);
	};
}