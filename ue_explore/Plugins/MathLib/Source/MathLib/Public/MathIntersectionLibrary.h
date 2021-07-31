
#pragma once
#include "CoreMinimal.h"

namespace S 
{
	class MATHLIB_API FMathIntersectionLibrary
	{
	public:
		static bool RayAABB(FVector ro,FVector rd,FVector boundMin,FVector boundMax,float& minDist,float& maxDist);
		static bool RaySphere(FVector ro,FVector rd,FVector center,float radius,float& minDist,float& maxDist);
	};
}