
#include "MathLibrary.h"

void S::FMathLibrary::Convex(TArray<FVector>& points,TArray<FVector>& convexPoints)
{
	FVector stdN = FVector(0, 0, 1);
	FVector yMin(0, FLT_MAX, 0);
	FVector yMax(0, FLT_MIN, 0);
	for (int32 i = 0; i < points.Num(); i++) {
		FVector point = points[i];
		if (point.Y < yMin.Y) {
			yMin = point;
		}
		else if (point.Y > yMax.Y) {
			yMax = point;
		}
	}
	points.Remove(yMin);
	points.Remove(yMax);
	FMathLibrary::Convex_FarthestInSection(stdN, yMin, yMax, points, convexPoints);
	FMathLibrary::Convex_FarthestInSection(stdN, yMax, yMin, points, convexPoints);
}

FMatrix S::FMathLibrary::MatrixFromAToB(FVector A, FVector B)
{
	check(A != B)
	FMatrix R;
	FVector X = A.GetSafeNormal();
	FVector Z = FVector::CrossProduct(A, B).GetSafeNormal();
	FVector Y = FVector::CrossProduct(Z, X).GetSafeNormal();
	R.SetAxis(0, X);
	R.SetAxis(1, Y);
	R.SetAxis(2, Z);
	return R;
}

float S::FMathLibrary::DistanceToVector(FVector p, FVector o, FVector dir)
{
	FVector OP = p - o;
	FVector opDir;
	float opMagnitude;
	OP.ToDirectionAndLength(opDir,opMagnitude);
	float dist = FMath::Sin(FMath::Acos(FVector::DotProduct(opDir, dir))) * opMagnitude;
	return dist;
}

void S::FMathLibrary::CalcAABB(TArray<FVector> points, FVector& boundMin, FVector& boundMax)
{
	float minX = FLT_MAX, minY = FLT_MAX, minZ = FLT_MAX;
	float maxX = FLT_MIN, maxY = FLT_MIN, maxZ = FLT_MIN;
	for (int32 i = 0; i < points.Num(); i++) {
		FVector& point = points[i];
		minX = FMath::Min(point.X, minX);
		minY = FMath::Min(point.Y, minY);
		minZ = FMath::Min(point.Z, minZ);
		maxX = FMath::Max(point.X, maxX);
		maxY = FMath::Max(point.Y, maxY);
		maxZ = FMath::Max(point.Z, maxZ);
	}
	boundMin = FVector(minX, minY, minZ);
	boundMax = FVector(maxX, maxY, maxZ);
}

void S::FMathLibrary::CalcSphere(TArray<FVector> points, FVector& center, float radius)
{

}

#pragma region privates

void S::FMathLibrary::Convex_FarthestInSection(FVector stdN, FVector begin, FVector end, TArray<FVector>& points, TArray<FVector>& convexPoints)
{
	if (points.Num() <= 0) {
		convexPoints.Add(end);
		return;
	}

	FVector splitDir = (end - begin).GetSafeNormal();

	float maxDist = FLT_MIN;
	FVector farthestPoint;
	for (int32 i = 0; i < points.Num(); i++) {
		FVector& point = points[i];
		FVector dir = point - begin;
		FVector N = FVector::CrossProduct(splitDir, dir);
		float sign = FMath::Sign<float>(FVector::DotProduct(stdN, N));
		if (sign > 0) {
			float dist = FMathLibrary::DistanceToVector(point, begin, splitDir);
			if (dist > maxDist) {
				maxDist = dist;
				farthestPoint = point;
			}
		}
	}
	if (maxDist == FLT_MIN)
	{
		convexPoints.Add(end);
		return;
	}
	points.Remove(farthestPoint);

	FVector edgeDir0 = farthestPoint - begin;
	TArray<FVector> section0;
	FVector edgeDir1 = end - farthestPoint;
	TArray<FVector> section1;
	for (int32 i = 0; i < points.Num(); i++) {
		FVector& point = points[i];
		bool passed = false;
		// edge 0
		{
			FVector dir = point - begin;
			FVector N = FVector::CrossProduct(edgeDir0, dir);
			float sign = FMath::Sign<float>(FVector::DotProduct(stdN, N));
			if (sign > 0) {
				section0.Add(point);
				passed = true;
			}
		}
		// edge 1
		{
			if( passed )
				continue;
			FVector dir = point - farthestPoint;
			FVector N = FVector::CrossProduct(edgeDir1, dir);
			float sign = FMath::Sign<float>(FVector::DotProduct(stdN, N));
			if (sign > 0) section1.Add(point);
		}
	}
	FMathLibrary::Convex_FarthestInSection(stdN, begin, farthestPoint, section0, convexPoints);
	FMathLibrary::Convex_FarthestInSection(stdN, farthestPoint, end, section1, convexPoints);
}

#pragma endregion privates