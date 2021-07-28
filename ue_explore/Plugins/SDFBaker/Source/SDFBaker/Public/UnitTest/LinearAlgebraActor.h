
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LinearAlgebraActor.generated.h"

UCLASS(Blueprintable)
class SDFBAKER_API ALinearAlgebraActor : public AActor
{
	GENERATED_BODY()
public:
	ALinearAlgebraActor();

	UFUNCTION(BlueprintCallable)
	void DrawClosestDistance(class UStaticMeshComponent* SMC,FVector point);

private:

	void DrawLine(FVector start,FVector end, FColor color);
};