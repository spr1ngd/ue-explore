
#include "SignedDistanceFieldLibrary.h"
#include "Engine/StaticMesh.h"
#include "SignedDistanceFieldCommon.h"
#include "StaticMeshResources.h"
#include "Rendering/PositionVertexBuffer.h"
#if WITH_EDITOR
#include "AssetRegistry/AssetRegistryModule.h"
#include "FileHelpers.h"
#endif

void USignedDistanceFieldLibrary::ExtractMeshInfo(UStaticMeshComponent* SMC, TArray<FVertex>& vertices, TArray<FTriangle>& triangles)
{
	UStaticMesh* staticMesh = SMC->GetStaticMesh();
	FTransform localToWorld = SMC->GetComponentTransform();
	
	if (nullptr == staticMesh && staticMesh->RenderData->LODResources.Num() <= 0)
		return;
	FStaticMeshLODResources* res = &staticMesh->RenderData->LODResources[0];
	FStaticMeshVertexBuffers* vbo = &res->VertexBuffers;
	FPositionVertexBuffer* vertexBuffer = &vbo->PositionVertexBuffer;
	if (vertexBuffer) {
		int32 num = vertexBuffer->GetNumVertices();
		for (int32 index = 0; index < num; index++) {
			FVector positionOS = vertexBuffer->VertexPosition(index);
			FVector positionWS = localToWorld.TransformPosition(positionOS);
			vertices.Add(FVertex(positionWS));
		}
	}
	FRawStaticIndexBuffer* ibo = &res->IndexBuffer;
	// get triangle data
	int32 indexNum = ibo->GetNumIndices();
	for (int32 i = 0; i < indexNum; i += 3) {
		int32 ai = ibo->GetIndex(i + 0);
		int32 bi = ibo->GetIndex(i + 1);
		int32 ci = ibo->GetIndex(i + 2);
		triangles.Add(FTriangle(vertices[ai], vertices[bi], vertices[ci]));
	}
}

UTexture2D* USignedDistanceFieldLibrary::CreateTexture(FString dir, FString texName, int32 width, int32 height, TArray<FColor>& colors)
{
#if WITH_EDITOR
	FString sourceTexName = texName;
	FString packageName = dir.Append(texName);
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
#elif
	return nullptr;
#endif
}

float USignedDistanceFieldLibrary::SDFPolygon2D(FVector sp, TArray<FVector>& points)
{
	return 0.0f;
}
