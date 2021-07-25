
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
	FVector VolumeTextureSize = FVector(10,10,10);

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

	void CalcSDF(TArray<FVertex> vertices);
	void CalcSDF(TArray<FTriangle> triangles);

	void VisualizeVolumeVoxel();
	void ExtractMeshInfo(class UStaticMesh* staticMesh,TArray<FVertex>& vertices,TArray<FTriangle>& triangles);
};
