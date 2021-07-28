
#include "SignedDistanceFieldLibrary.h"
#include "Engine/StaticMesh.h"
#include "SignedDistanceFieldCommon.h"
#include "StaticMeshResources.h"
#include "Rendering/PositionVertexBuffer.h"

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