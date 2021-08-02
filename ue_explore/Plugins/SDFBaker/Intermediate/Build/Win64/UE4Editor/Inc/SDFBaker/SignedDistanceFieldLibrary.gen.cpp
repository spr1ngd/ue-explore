// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SDFBaker/Public/SignedDistanceFieldLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSignedDistanceFieldLibrary() {}
// Cross Module References
	SDFBAKER_API UClass* Z_Construct_UClass_USignedDistanceFieldLibrary_NoRegister();
	SDFBAKER_API UClass* Z_Construct_UClass_USignedDistanceFieldLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_SDFBaker();
// End Cross Module References
	void USignedDistanceFieldLibrary::StaticRegisterNativesUSignedDistanceFieldLibrary()
	{
	}
	UClass* Z_Construct_UClass_USignedDistanceFieldLibrary_NoRegister()
	{
		return USignedDistanceFieldLibrary::StaticClass();
	}
	struct Z_Construct_UClass_USignedDistanceFieldLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USignedDistanceFieldLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_SDFBaker,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignedDistanceFieldLibrary_Statics::Class_MetaDataParams[] = {
		{ "BlueprintThreadSafe", "" },
		{ "IncludePath", "SignedDistanceFieldLibrary.h" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldLibrary.h" },
		{ "ScriptName", "MathLibrary" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USignedDistanceFieldLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USignedDistanceFieldLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USignedDistanceFieldLibrary_Statics::ClassParams = {
		&USignedDistanceFieldLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USignedDistanceFieldLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USignedDistanceFieldLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USignedDistanceFieldLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USignedDistanceFieldLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USignedDistanceFieldLibrary, 2504577813);
	template<> SDFBAKER_API UClass* StaticClass<USignedDistanceFieldLibrary>()
	{
		return USignedDistanceFieldLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USignedDistanceFieldLibrary(Z_Construct_UClass_USignedDistanceFieldLibrary, &USignedDistanceFieldLibrary::StaticClass, TEXT("/Script/SDFBaker"), TEXT("USignedDistanceFieldLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USignedDistanceFieldLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
