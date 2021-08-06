
#pragma once
#include "CoreMinimal.h"

namespace S 
{
	class MATHLIB_API FMathLibrary 
	{
	public:
		static void Convex(TArray<FVector>& points,TArray<FVector>& convexPoints);
		static FMatrix MatrixFromAToB(FVector A,FVector B);
		static float DistanceToVector(FVector p,FVector o,FVector dir);

		static void CalcAABB(TArray<FVector> points, FVector& center,FVector& extent);
		static void CalcSphere(TArray<FVector> points, FVector& center, float radius);

	private:
		static void Convex_FarthestInSection(FVector stdN, FVector begin, FVector end, TArray<FVector>& points, TArray<FVector>& convexPoints);
	};
}