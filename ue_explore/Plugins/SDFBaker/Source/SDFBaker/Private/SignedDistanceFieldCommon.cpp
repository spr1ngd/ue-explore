
#include "SignedDistanceFieldCommon.h"

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

#pragma region FTriangle

FTriangle::FTriangle(FVertex a, FVertex b, FVertex c)
{
	this->A = a;
	this->B = b;
	this->C = c;
}

#pragma endregion FTriangle