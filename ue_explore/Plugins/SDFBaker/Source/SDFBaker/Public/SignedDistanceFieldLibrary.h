
// author : spr1ngd

#pragma once
#include "CoreMinimal.h"

class SDFBAKER_API USignedDistanceFieldLibrary
{
public:
	static void ExtractMeshInfo(class UStaticMeshComponent* SMC,TArray<class FVertex>& vertices,TArray<class FTriangle>& triangles);
	static class UTexture2D* CreateTexture(FString dir, FString texName, int32 width, int32 height, TArray<FColor>& colors);

	// 2d polygon sdf
	static float SDFPolygon2D(FVector sp,TArray<FVector>& points);
};