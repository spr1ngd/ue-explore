
#include "UnitTest/MathLibActor.h"
#include "MathLibrary.h"
#include "MathIntersectionLibrary.h"

TArray<FVector> AMathLibActor::Convex(TArray<FVector> points, FVector o, FVector on)
{
	TArray<FVector> convexPoints;
	S::FMathLibrary::Convex(points, convexPoints);
	return convexPoints;
}

bool AMathLibActor::RayBox(FVector ro, FVector rd, FVector boundMin, FVector boundMax, float& minDist, float& maxDist)
{
	return S::FMathIntersectionLibrary::RayAABB(ro, rd, boundMin, boundMax, minDist, maxDist);
}

bool AMathLibActor::RaySphere(FVector ro, FVector rd, FVector center, float radius, float& minDist, float& maxDist)
{
	return S::FMathIntersectionLibrary::RaySphere(ro, rd, center, radius, minDist, maxDist);
}
