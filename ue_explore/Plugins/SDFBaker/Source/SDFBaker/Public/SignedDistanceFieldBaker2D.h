
// author : spr1ngd
// desc   : bake 2d signed distance field info to texture

#pragma once
#include "CoreMinimal.h"
#include "SignedDistanceFieldBaker2D.generated.h"

UCLASS(Blueprintable)
class USignedDistanceFieldBaker2D : public UObject
{
	GENERATED_BODY()
private:
	
public:

	UFUNCTION(BlueprintCallable)
	class UTexture2D* Bake(TArray<FVector> points);
};
