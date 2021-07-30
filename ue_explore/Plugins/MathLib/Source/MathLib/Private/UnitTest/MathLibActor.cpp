
#include "UnitTest/MathLibActor.h"
#include "MathLibrary.h"

TArray<FVector> AMathLibActor::Convex(TArray<FVector> points, FVector o, FVector on)
{
	TArray<FVector> convexPoints;
	S::FMathLibrary::Convex(points, convexPoints);
	return convexPoints;
}