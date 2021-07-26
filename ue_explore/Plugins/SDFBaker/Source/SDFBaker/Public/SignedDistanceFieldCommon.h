
// author : spr1ngd
// desc   : all shared class/struct used in signed distance field module.

#pragma once
#include "CoreMinimal.h"

class FVertex 
{
public:
	FVector Position;
	FVector Normal;

	FVertex() {}
	FVertex(FVector pos);
	FVertex(FVector pos,FVector normal);
};

class FTriangle
{
public:
	FVertex A;
	FVertex B;
	FVertex C;

	FTriangle() {}
	FTriangle(FVertex a,FVertex b,FVertex c);

	// closest distance between triangle and point
	float ClosestDistance(FVector p);
	// distance between face that triangle lies on and point
	float Distance(FVector p);
	// point p is in current angle
	bool InTriangle(FVector p);
	// get triangular face normal
	FVector CalcNormal();
};