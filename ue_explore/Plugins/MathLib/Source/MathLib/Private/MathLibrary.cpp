
#include "MathLibrary.h"

void S::FMathLibrary::Convex(TArray<FVector>& points, FVector pN,TArray<FVector>& convexPoints)
{
	FVector stdN = FVector(0, 0, 1);
	FMatrix R = FMatrix::Identity; // FMathLibrary::MatrixFromAToB(stdN, pN);

	// spr1ngd : TODO: transform input points , please check MatrixFromAToB is correct.

	FVector yMin(0, FLT_MAX, 0);
	FVector yMax(0, FLT_MIN, 0);
	for (int32 i = 0; i < points.Num(); i++) {
		FVector point = R.TransformPosition(points[i]);
		if (point.Y < yMin.Y) {
			yMin = point;
		}
		else if (point.Y > yMax.Y) {
			yMax = point;
		}
	}
	points.Remove(yMin);
	points.Remove(yMax);
	float rightSlotIndex = convexPoints.Insert(yMin, 0);
	float leftSlotIndex = convexPoints.Insert(yMax, 1);
	FMathLibrary::Convex_Internal(stdN, yMin, yMax, points, convexPoints, rightSlotIndex, leftSlotIndex);
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

#pragma region privates

void S::FMathLibrary::Convex_Internal(
	FVector stdN, FVector begin, FVector end, TArray<FVector> points,
	TArray<FVector>& convexPoints, int32 rightSlotIndex,int32 leftSlotIndex)
{
	FVector splitDir = (end - begin).GetSafeNormal();
	float leftMaxDist = FLT_MIN;
	FVector left(0, 0, 0);
	TArray<FVector> leftSections;
	float rightMaxDist = FLT_MIN;
	FVector right(0, 0, 0);
	TArray<FVector> rightSections;

	for (int32 i = 0; i < points.Num(); i++) {
		FVector point = points[i];
		FVector dir = point - begin;
		FVector N = FVector::CrossProduct(splitDir, dir);
		float dist = FMathLibrary::DistanceToVector(point, begin, splitDir);
		float sign = FMath::Sign<float>(FVector::DotProduct(stdN, N));
		if (sign > 0) {
			rightSections.Add(point);
			if (dist > rightMaxDist) {
				rightMaxDist = dist;
				right = point;
			}
		}
		else if (sign < 0) {
			leftSections.Add(point);
			if (dist > leftMaxDist) {
				leftMaxDist = dist;
				left = point;
			}
		}
	}
	if (rightMaxDist > FLT_MIN) {
		rightSections.Remove(right);
		rightSlotIndex = convexPoints.Insert(right, rightSlotIndex);
		FMathLibrary::Convex_Internal(stdN, begin, right, rightSections, convexPoints, rightSlotIndex, leftSlotIndex);
	}
	if (leftMaxDist > FLT_MIN) {
		leftSections.Remove(left);
		leftSlotIndex = convexPoints.Insert(left, leftSlotIndex);
		FMathLibrary::Convex_Internal(stdN, end, left, leftSections, convexPoints, rightSlotIndex, leftSlotIndex);
	}
}

#pragma endregion privates