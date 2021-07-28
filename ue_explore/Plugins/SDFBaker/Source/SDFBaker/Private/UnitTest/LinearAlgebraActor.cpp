
#include "UnitTest/LinearAlgebraActor.h"
#include "Components/StaticMeshComponent.h"
#include "SignedDistanceFieldCommon.h"
#include "DrawDebugHelpers.h"
#include "SignedDistanceFieldLibrary.h"

ALinearAlgebraActor::ALinearAlgebraActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALinearAlgebraActor::DrawClosestDistance(UStaticMeshComponent* SMC, FVector point)
{
	TArray<FVertex> vertices;
	TArray<FTriangle> triangles;
	USignedDistanceFieldLibrary::ExtractMeshInfo(SMC, vertices, triangles);

	float minT = 999999999.0f;
	FVector intersectionPoint;
	for (FTriangle triangle : triangles) {
		FVector temp;
		float closestDistance = triangle.ClosestDistance(point, temp);
		if (FMath::Abs(closestDistance) < minT)
		{
			intersectionPoint = temp;
			minT = FMath::Abs(closestDistance);
		}
	}
	DrawLine(point, intersectionPoint, minT >= 0.0f ? FColor::Green : FColor::Red);
}

void ALinearAlgebraActor::DrawLine(FVector start, FVector end, FColor color)
{
	DrawDebugLine(this->GetWorld(),start,end, color,false,0.0f,0,1.0f);
}
