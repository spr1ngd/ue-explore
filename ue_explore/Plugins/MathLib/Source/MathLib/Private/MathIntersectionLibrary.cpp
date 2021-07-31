
#include "MathIntersectionLibrary.h"
#include "Math/UnrealMathUtility.h"

bool S::FMathIntersectionLibrary::RayAABB(FVector ro, FVector rd, FVector boundMin, FVector boundMax, float& minDist, float& maxDist)
{
	FVector t0 = (boundMin - ro) / rd;
	FVector t1 = (boundMax - ro) / rd;
	FVector tmin = FVector(FMath::Min(t0.X, t1.X), FMath::Min(t0.Y, t1.Y), FMath::Min(t0.Z, t1.Z));
	FVector tmax = FVector(FMath::Max(t0.X, t1.X), FMath::Max(t0.Y, t1.Y), FMath::Max(t0.Z, t1.Z));
	float da = FMath::Max3(tmin.X, tmin.Y, tmin.Z);
	float db = FMath::Min3(tmax.X, tmax.Y, tmax.Z);
	bool intersection = da < db;
	if (intersection) {
		minDist = FMath::Max(0.0f, da);
		maxDist = FMath::Max(0.0f, db);
	}
	return intersection;
}

bool S::FMathIntersectionLibrary::RaySphere(FVector ro, FVector rd, FVector center, float radius, float& minDist, float& maxDist)
{
	FVector oc = center - ro;
	float l = FVector::DotProduct(oc,rd);
	float d = FMath::Sqrt(FVector::DotProduct(oc,oc) - l*l);
	if (d > radius)
		return false;
	float hl = FMath::Sqrt(radius* radius - d*d);
	minDist = l - hl;
	maxDist = l + hl;
	return true;
}
