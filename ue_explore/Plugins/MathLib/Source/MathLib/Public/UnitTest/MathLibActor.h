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
};