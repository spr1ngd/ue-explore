
#include "SignedDistanceFieldBaker.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Math/BoxSphereBounds.h"
#include "Math/Box.h"
#include "StaticMeshResources.h"
#include "Rendering/PositionVertexBuffer.h"

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
		VisualizeVolume();
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
	ExtractMeshInfo(SM, vertices, triangles);

	FBoxSphereBounds bounds = SMC->Bounds;
	FBox box = bounds.GetBox();
	FVector volumeCenter = box.GetCenter();
	FVector volumeExtent = box.GetExtent();
	volumeExtent *= (1 + this->VolumeIncreasePercent);

	if( this->DrawDebugInfo )
		DrawDebugBox(world,volumeCenter,volumeExtent,FQuat::Identity,FColor::Green,false,0.0f,0,this->DebugLineWidth);

	// visualize voxel 
	FVector min = volumeCenter - volumeExtent;
	FVector max = volumeCenter + volumeExtent;
	FVector size = volumeExtent * 2.0f;
	FVector voxelSize = FVector(
		size.X / this->VolumeTextureSize.X,
		size.Y / this->VolumeTextureSize.Y, 
		size.Z / this->VolumeTextureSize.Z);

	for (float z = 0.0f; z < size.Z; z += voxelSize.Z) {
		for (float y = 0.0f; y < size.Y; y += voxelSize.Y) {
			for (float x = 0.0f; x < size.X; x += voxelSize.X) {
				FVector voxelMin = min + FVector(x, y, z);
				FVector voxelMax = voxelMin + voxelSize;
				FVector voxelCenter = (voxelMax + voxelMin) * 0.5f;
				FVector voxelExtent = (voxelMax - voxelMin) * 0.5f;
				if (this->DrawDebugInfo)
					DrawDebugBox(world, voxelCenter, voxelExtent, FQuat::Identity, FColor::Red, false, 0.0f, 0, this->DebugLineWidth);


			}
		}
	}
}

void ASignedDistanceFieldBaker::VisualizeVolumeVoxel()
{

}

void ASignedDistanceFieldBaker::CalcSDF(TArray<FVertex> vertices)
{

}

void ASignedDistanceFieldBaker::CalcSDF(TArray<FTriangle> triangles)
{

}

void ASignedDistanceFieldBaker::ExtractMeshInfo(UStaticMesh* staticMesh, TArray<FVertex>& vertices, TArray<FTriangle>& triangles)
{
	if (nullptr == staticMesh && staticMesh->RenderData->LODResources.Num() <= 0)
		return;
	FStaticMeshLODResources res = staticMesh->RenderData->LODResources[0];
	FStaticMeshVertexBuffers vbo = res.VertexBuffers;
	FPositionVertexBuffer* vertexBuffer = &vbo.PositionVertexBuffer;
	if (vertexBuffer) {
		int32 num = vertexBuffer->GetNumVertices();
		for (int32 index = 0; index < num; index++) {
			FVector positionOS = vertexBuffer->VertexPosition(index);
			vertices.Add(FVertex(positionOS));
		}
	}
	FRawStaticIndexBuffer ibo = res.IndexBuffer;
	// get triangle data
}
