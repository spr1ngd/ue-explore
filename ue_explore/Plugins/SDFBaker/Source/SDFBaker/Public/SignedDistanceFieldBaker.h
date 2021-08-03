
// author : spr1ngd
// desc   : visualize signed distance field

#pragma once
#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "SignedDistanceFieldBaker.generated.h"

UCLASS(Blueprintable, BlueprintType)
class SDFBAKER_API ASignedDistanceFieldBaker : public AStaticMeshActor
{
	GENERATED_BODY()

public:

	// editor debug

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SDF.Debug")
		bool DrawDebugInfo = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SDF.Debug")
		bool UseTickInEditor = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SDF.Debug")
		float DebugLineWidth = 5.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SDF.Debug")
		float VoxelSize = 10.0f;

	// runtime 

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SDF")
	float VolumeIncreasePercent = 0.2f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SDF")
		int32 VolumeTextureTileX = 10;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SDF")
		int32 VolumeTextureTileY = 10;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SDF")
		int32 VolumeTextureTileZ = 10;

	class UVolumeTexture* SDFVolumeTexture = nullptr;

public:
	ASignedDistanceFieldBaker();
	virtual void Tick(float DeltaSeconds) override;
	virtual bool ShouldTickIfViewportsOnly() const override;
	virtual void TickInEditor(float DeltaSeconds);

	// visualize aabb 
	// visualize voxel of volume texture

	UFUNCTION(BlueprintCallable, Category = "SDF")
		void VisualizeVolume();

private:

	float CalcSDF(FVector o ,TArray<class FVertex>& vertices);
	float CalcSDF(FVector o ,TArray<class FTriangle>& triangles);

	void VisualizeVolumeVoxel();

	UTexture2D* CreateSliceTexture(int32 width,int32 height,TArray<FColor>& colors);
	UVolumeTexture* CreateVolumeTexture(int32 tileX, int32 tileY, int32 tileZ, UTexture2D* sourceTex);

	// package default  =  "/Game/"
	void SaveVolumeTexture(UVolumeTexture* volumeTexture,FString packageName);
};
