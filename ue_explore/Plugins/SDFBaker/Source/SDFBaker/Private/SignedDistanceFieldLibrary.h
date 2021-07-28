
// author : spr1ngd

#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SignedDistanceFieldLibrary.generated.h"

UCLASS(meta = (BlueprintThreadSafe, ScriptName = "MathLibrary"))
class SDFBAKER_API USignedDistanceFieldLibrary: public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static void ExtractMeshInfo(class UStaticMeshComponent* SMC,TArray<class FVertex>& vertices,TArray<class FTriangle>& triangles);
};