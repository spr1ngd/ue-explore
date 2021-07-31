#pragma once
#include "CoreMinimal.h"
#include "MathLibActor.generated.h"

UCLASS()
class AMathLibActor : public AActor 
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
		TArray<FVector> Convex(TArray<FVector> points,FVector o,FVector on);

	// intersection
	UFUNCTION(BlueprintCallable)
	bool RayBox(FVector ro,FVector rd,FVector boundMin,FVector boundMax,float& minDist,float& maxDist);
	UFUNCTION(BlueprintCallable)
	bool RaySphere(FVector ro,FVector rd,FVector center,float radius,float& minDist,float& maxDist);
};