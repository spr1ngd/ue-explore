
#include "SignedDistanceFieldCommon.h"
#include "Kismet/KismetMathLibrary.h"

#pragma region FVertex 

FVertex::FVertex(FVector pos)
{
	this->Position = pos;
	this->Normal = FVector(0, 1, 0);
}

FVertex::FVertex(FVector pos, FVector normal)
{
	this->Position = pos;
	this->Normal = normal;
}

#pragma endregion FVertex 

#pragma region FTriangle

FTriangle::FTriangle(FVertex a, FVertex b, FVertex c)
{
	this->A = a;
	this->B = b;
	this->C = c;
}

float FTriangle::ClosestDistance(FVector p)
{
	return -1.0f;
}

float FTriangle::Distance(FVector p)
{
	FVector faceNormal = this->CalcNormal();
	FVector APDir;
	float APMagnitude;
	(p - this->A.Position).ToDirectionAndLength(APDir,APMagnitude);
	float cosTheta = FVector::DotProduct(faceNormal, APDir);
	float distance = cosTheta * APMagnitude;
	return distance;
}

bool FTriangle::InTriangle(FVector p)
{
	FVector AB = (this->B.Position - this->A.Position).GetSafeNormal();
	FVector BC = (this->C.Position - this->B.Position).GetSafeNormal();
	FVector AP = (p - this->A.Position).GetSafeNormal();
	FVector BP = (p - this->B.Position).GetSafeNormal();
	FVector N0 = FVector::CrossProduct(AB,AP);
	FVector N1 = FVector::CrossProduct(BC,BP);

	// sign n01
	// float sign = UKismetMathLibrary::SignOfFloat(FVector::DotProduct(N0,N1));
	float sign = FMath::Sign<float>(FVector::DotProduct(N0, N1));
	if (sign < 0)
		return false;

	FVector CA = (this->A.Position - this->C.Position).GetSafeNormal();
	FVector CP = (p - this->C.Position).GetSafeNormal();
	FVector N2 = FVector::CrossProduct(CA, CP);
	sign = FMath::Sign<float>(FVector::DotProduct(N0, N2));
	return sign > 0.0f ? true : false;
}

FVector FTriangle::CalcNormal()
{
	FVector AB = (this->B.Position - this->A.Position).GetSafeNormal();
	FVector AC = (this->C.Position - this->A.Position).GetSafeNormal();
	FVector normal = FVector::CrossProduct(AB, AC).GetSafeNormal();
	return normal;
}

#pragma endregion FTriangle