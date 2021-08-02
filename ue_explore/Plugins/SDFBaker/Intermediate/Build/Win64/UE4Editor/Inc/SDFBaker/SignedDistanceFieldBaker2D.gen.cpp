// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SDFBaker/Public/SignedDistanceFieldBaker2D.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSignedDistanceFieldBaker2D() {}
// Cross Module References
	SDFBAKER_API UClass* Z_Construct_UClass_USignedDistanceFieldBaker2D_NoRegister();
	SDFBAKER_API UClass* Z_Construct_UClass_USignedDistanceFieldBaker2D();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_SDFBaker();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(USignedDistanceFieldBaker2D::execBake)
	{
		P_GET_TARRAY(FVector,Z_Param_points);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTexture2D**)Z_Param__Result=P_THIS->Bake(Z_Param_points);
		P_NATIVE_END;
	}
	void USignedDistanceFieldBaker2D::StaticRegisterNativesUSignedDistanceFieldBaker2D()
	{
		UClass* Class = USignedDistanceFieldBaker2D::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Bake", &USignedDistanceFieldBaker2D::execBake },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics
	{
		struct SignedDistanceFieldBaker2D_eventBake_Parms
		{
			TArray<FVector> points;
			UTexture2D* ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_points_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_points;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_points_Inner = { "points", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_points = { "points", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SignedDistanceFieldBaker2D_eventBake_Parms, points), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SignedDistanceFieldBaker2D_eventBake_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_points_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_points,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker2D.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USignedDistanceFieldBaker2D, nullptr, "Bake", nullptr, nullptr, sizeof(SignedDistanceFieldBaker2D_eventBake_Parms), Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USignedDistanceFieldBaker2D_NoRegister()
	{
		return USignedDistanceFieldBaker2D::StaticClass();
	}
	struct Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SDFBaker,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake, "Bake" }, // 482546587
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SignedDistanceFieldBaker2D.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker2D.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USignedDistanceFieldBaker2D>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::ClassParams = {
		&USignedDistanceFieldBaker2D::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USignedDistanceFieldBaker2D()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USignedDistanceFieldBaker2D, 3218711857);
	template<> SDFBAKER_API UClass* StaticClass<USignedDistanceFieldBaker2D>()
	{
		return USignedDistanceFieldBaker2D::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USignedDistanceFieldBaker2D(Z_Construct_UClass_USignedDistanceFieldBaker2D, &USignedDistanceFieldBaker2D::StaticClass, TEXT("/Script/SDFBaker"), TEXT("USignedDistanceFieldBaker2D"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USignedDistanceFieldBaker2D);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
