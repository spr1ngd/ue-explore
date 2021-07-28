
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
	FVertex(FVector pos, FVector normal);
};

class FTriangleEdge
{
public:
	FVertex A;
	FVertex B;
	FVector Edge;
	FVector Direction;

	FTriangleEdge() {}
	FTriangleEdge(FVertex a, FVertex b);

	float Distance(FVector p);
};

class FTriangle
{
public:
	FVertex A;
	FVertex B;
	FVertex C;

	FTriangleEdge AB;
	FTriangleEdge BC;
	FTriangleEdge CA;

	FTriangle() {}
	FTriangle(FVertex a, FVertex b, FVertex c);

	// closest distance between triangle and point
	float ClosestDistance(FVector p);
	float ClosestDistance(FVector p,FVector& outIntersectionPoint);
	// distance between face that triangle lies on and point
	float ProjectionDistance(FVector p);
	// point p is in current angle
	bool InTriangle(FVector p);
	// p's subpoint in triangle face.
	void Project(FVector p, float& dist, FVector& subpoint);
	// get triangular face normal
	FVector CalcNormal();
};