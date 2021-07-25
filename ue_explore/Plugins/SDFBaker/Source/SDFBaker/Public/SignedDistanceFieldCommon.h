
// author : spr1ngd
// desc   : all shared class/struct used in signed distance field module.

#pragma once
#include "CoreMinimal.h"

class FVertex 
{
public:
	FVector Position;
	FVector Normal;

	FVertex(FVector pos);
	FVertex(FVector pos,FVector normal);
};

class FTriangle
{
public:
	FVertex A;
	FVertex B;
	FVertex C;

	FTriangle(FVertex a,FVertex b,FVertex c);
};