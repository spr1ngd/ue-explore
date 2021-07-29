
#pragma once
#include "CoreMinimal.h"

namespace S 
{
	class MATHLIB_API FMathLibrary 
	{
	public:
		static void Convex(TArray<FVector>& points,FVector pN,TArray<FVector>& convexPoints);
		static FMatrix MatrixFromAToB(FVector A,FVector B);
		static float DistanceToVector(FVector p,FVector o,FVector dir);

	private:
		static void Convex_Internal(
			FVector stdN, FVector begin, FVector end, TArray<FVector> points,
			TArray<FVector>& convexPoints, int32 rightSlotIndex, int32 leftSlotIndex);
	};
}