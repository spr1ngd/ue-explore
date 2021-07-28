
#include "SignedDistanceFieldBaker.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Math/BoxSphereBounds.h"
#include "Math/Box.h"
#include "StaticMeshResources.h"
#include "Rendering/PositionVertexBuffer.h"
#include "Engine/VolumeTexture.h"
#include "Factories/VolumeTextureFactory.h"
#include "SignedDistanceFieldCommon.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "FileHelpers.h"
#include "Engine/StaticMesh.h"
#include "SignedDistanceFieldLibrary.h"

ASignedDistanceFieldBaker::ASignedDistanceFieldBaker()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASignedDistanceFieldBaker::Tick(float DeltaSeconds)
{
	UWorld* world = this->GetWorld();
	if (world && world->WorldType == EWorldType::Editor && this->UseTickInEditor) {
#if WITH_EDITOR
		this->TickInEditor(DeltaSeconds);
#endif
	}
	else {
		Super::Tick(DeltaSeconds);
	}
}

bool ASignedDistanceFieldBaker::ShouldTickIfViewportsOnly() const
{
	UWorld* world = this->GetWorld();
	if (world && world->WorldType == EWorldType::Editor) {
		return true;
	}
	return false;
}

void ASignedDistanceFieldBaker::TickInEditor(float DeltaSeconds)
{
	VisualizeVolume();
}

void ASignedDistanceFieldBaker::VisualizeVolume()
{
	UWorld* world = this->GetWorld();

	UStaticMeshComponent* SMC = this->GetStaticMeshComponent();
	UStaticMesh* SM = SMC->GetStaticMesh();

	// get mesh vertices and triangles
	TArray<FVertex> vertices;
	TArray<FTriangle> triangles;
	USignedDistanceFieldLibrary::ExtractMeshInfo(SMC, vertices, triangles);

	FBoxSphereBounds bounds = SMC->Bounds;
	FBox box = bounds.GetBox();
	FVector volumeCenter = box.GetCenter();
	FVector volumeExtent = box.GetExtent();
	volumeExtent *= (1 + this->VolumeIncreasePercent);

	DrawDebugBox(world,volumeCenter,volumeExtent,FQuat::Identity,FColor::Green,false,0.0f,0,this->DebugLineWidth);

	// visualize voxel 
	FVector min = volumeCenter - volumeExtent;
	FVector max = volumeCenter + volumeExtent;
	FVector size = volumeExtent * 2.0f;
	FVector voxelSize = FVector(
		size.X / VolumeTextureTileX,
		size.Y / VolumeTextureTileY,
		size.Z / VolumeTextureTileZ);

	TArray<FColor> sliceColors;
	for (float z = size.Z; z >=0; z -= voxelSize.Z) {
		for (float y = 0.0f; y < size.Y; y += voxelSize.Y) {
			for (float x = 0.0f; x < size.X; x += voxelSize.X) {
				FVector voxelMin = min + FVector(x, y, z);
				FVector voxelMax = voxelMin + voxelSize;
				FVector voxelCenter = (voxelMax + voxelMin) * 0.5f;
				FVector voxelExtent = (voxelMax - voxelMin) * 0.5f;
				if (this->DrawDebugInfo)
					DrawDebugBox(world, voxelCenter, voxelExtent, FQuat::Identity, FColor::Red, false, 0.0f, 0, this->DebugLineWidth);
				float minT = this->CalcSDF(voxelCenter, triangles);
				minT /= 250;
				FColor color = FLinearColor(minT,minT,minT).ToFColor(false);
				sliceColors.Push(color);
			}
		}
	}

	if (!this->SDFVolumeTexture) {
		// z轴在2d中纵向排列
		UTexture2D* sourceTex = this->CreateSliceTexture(VolumeTextureTileX, VolumeTextureTileY * VolumeTextureTileZ, sliceColors);
		UVolumeTexture* volumeTexture = this->CreateVolumeTexture(VolumeTextureTileX, VolumeTextureTileY, VolumeTextureTileZ, sourceTex);
		this->SDFVolumeTexture = volumeTexture;
		this->SaveVolumeTexture(volumeTexture, FString::Printf(TEXT("/Game/levels/SDF_Volume")));
	}
}

void ASignedDistanceFieldBaker::VisualizeVolumeVoxel()
{

}

float ASignedDistanceFieldBaker::CalcSDF(FVector o, TArray<FVertex> vertices)
{
	float minT = 99999999.9f;
	for (int32 i = 0; i < vertices.Num(); i++) {
		FVertex& vertex = vertices[i];
		minT = FMath::Min(minT,FVector::Distance(vertex.Position,o));
	}
	return minT;
}

float ASignedDistanceFieldBaker::CalcSDF(FVector o, TArray<FTriangle> triangles)
{
	float minT = 99999999.0f;
	for (int32 i = 0; i < triangles.Num(); i++) {
		FTriangle& triangle = triangles[i];
		minT = FMath::Min(minT,FMath::Abs(triangle.ClosestDistance(o)));
	}
	return minT;
}

void ASignedDistanceFieldBaker::ExtractMeshInfo(UStaticMesh* staticMesh, TArray<FVertex>& vertices, TArray<FTriangle>& triangles)
{
	if (nullptr == staticMesh && staticMesh->RenderData->LODResources.Num() <= 0)
		return;
	FStaticMeshLODResources* res = &staticMesh->RenderData->LODResources[0];
	FStaticMeshVertexBuffers* vbo = &res->VertexBuffers;
	FPositionVertexBuffer* vertexBuffer = &vbo->PositionVertexBuffer;
	if (vertexBuffer) {
		int32 num = vertexBuffer->GetNumVertices();
		for (int32 index = 0; index < num; index++) {
			FVector positionOS = vertexBuffer->VertexPosition(index);
			vertices.Add(FVertex(positionOS));
		}
	}
	FRawStaticIndexBuffer* ibo = &res->IndexBuffer;
	// get triangle data
}

UTexture2D* ASignedDistanceFieldBaker::CreateSliceTexture(int32 width, int32 height, TArray<FColor>& colors)
{
	FString sourceTexName = "SDF_SourceTexture";
	FString packageName = "/Game/levels/SDF_SourceTexture";
	UPackage* package = CreatePackage(NULL, *packageName);
	package->FullyLoad();
	UTexture2D* NewTexture = NewObject<UTexture2D>(package, *sourceTexName, RF_Public | RF_Standalone | RF_MarkAsRootSet);
	NewTexture->Source.Init(width, height, 1, 1, TSF_BGRA8);

	uint8* MipData = NewTexture->Source.LockMip(0);
	for (int32 y = 0; y < height; y++)
	{
		uint8* DestPtr = &MipData[(height - 1 - y) * width * sizeof(FColor)];
		FColor* SrcPtr = const_cast<FColor*>(&colors[(height - 1 - y) * width]);
		for (int32 x = 0; x < width; x++)
		{
			*DestPtr++ = SrcPtr->B;
			*DestPtr++ = SrcPtr->G;
			*DestPtr++ = SrcPtr->R;
			if (true)
			{
				*DestPtr++ = SrcPtr->A;
			}
			else
			{
				*DestPtr++ = 0xFF;
			}
			SrcPtr++;
		}
	}
	NewTexture->Source.UnlockMip(0);
	NewTexture->SRGB = false;
	NewTexture->PostEditChange();

	FAssetRegistryModule::AssetCreated(NewTexture);
	package->MarkPackageDirty();
	bool success = UPackage::SavePackage(package, NewTexture, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *packageName, GError, nullptr, true, true, SAVE_NoError);
	FEditorFileUtils::EPromptReturnCode returnCode = FEditorFileUtils::PromptForCheckoutAndSave({ package }, false, false);
	return NewTexture;
}

UVolumeTexture* ASignedDistanceFieldBaker::CreateVolumeTexture(int32 tileX, int32 tileY, int32 tileZ, UTexture2D* sourceTex)
{
	check(sourceTex);
	check(tileZ > 0);

	FString volumeTexName = "SDF_VolumeTexture";
	FString packageName = "/Game/levels/SDF_VolumeTexture";
	UPackage* package = CreatePackage(NULL, *packageName);
	package->FullyLoad();

	UVolumeTexture* volumeTex = NewObject<UVolumeTexture>(package,"SDF_VolumeTexture", EObjectFlags::RF_Public | EObjectFlags::RF_Standalone | EObjectFlags::RF_MarkAsRootSet);
	volumeTex->AddToRoot();
	volumeTex->MipGenSettings = TMGS_FromTextureGroup;
	volumeTex->NeverStream = true;
	volumeTex->CompressionNone = false;

	volumeTex->SRGB = sourceTex->SRGB;
	const FTextureSource& Source = sourceTex->Source;
	const int32 NumsPixels = sourceTex->PlatformData->SizeX * sourceTex->PlatformData->SizeY;
	if (NumsPixels > 0) {
		volumeTex->Source2DTexture = sourceTex;
		volumeTex->Source2DTileSizeX = tileX;
		volumeTex->Source2DTileSizeY = tileY;

		volumeTex->UpdateSourceFromSourceTexture();
		volumeTex->UpdateResource();
	}

	FAssetRegistryModule::AssetCreated(volumeTex);
	package->MarkPackageDirty();
	bool success = UPackage::SavePackage(package, volumeTex, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *packageName, GError, nullptr, true, true, SAVE_NoError);
	FEditorFileUtils::EPromptReturnCode returnCode = FEditorFileUtils::PromptForCheckoutAndSave({ package }, false, false);
	return volumeTex;
}

void ASignedDistanceFieldBaker::SaveVolumeTexture(UVolumeTexture* volumeTexture, FString packageName)
{
}