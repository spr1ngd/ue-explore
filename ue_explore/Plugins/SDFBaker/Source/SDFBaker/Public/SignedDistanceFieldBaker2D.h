
// author : spr1ngd
// desc   : bake 2d signed distance field info to texture

#pragma once
#include "CoreMinimal.h"
#include "AccelerationStructure/2D/Grid_2DSDF.h"
#include "SignedDistanceFieldBaker2D.generated.h"

UCLASS(Blueprintable)
class USignedDistanceFieldBaker2D : public UObject
{
	GENERATED_BODY()
private:
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 width = 256;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 height = 256;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float ExpandPercent = 0.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString exportDir = "";
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString exportTexName = "";
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool DrawDebugInfo = false;

	UFUNCTION(BlueprintCallable)
	class UTexture2D* Bake(TArray<FVector> points,FVector up);

	S::FGrid_2DSDF* bakedGrid;
	UFUNCTION(BlueprintCallable)
	void ShortestDistance(FVector sp,FVector& intersection);

private:

	float SDFPolygon2D(FVector sp,TArray<FVector>& points);
	void ExtractFloatItem(float value, float& pos, float& posSign, float& pow, float& powSign);

	void DrawAS(struct FBox_2DSDF* root, UWorld* world);
};
