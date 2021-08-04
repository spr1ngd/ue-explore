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
		P_GET_STRUCT(FVector,Z_Param_up);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTexture2D**)Z_Param__Result=P_THIS->Bake(Z_Param_points,Z_Param_up);
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
			FVector up;
			UTexture2D* ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_points_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_points;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_up;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_points_Inner = { "points", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_points = { "points", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SignedDistanceFieldBaker2D_eventBake_Parms, points), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_up = { "up", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SignedDistanceFieldBaker2D_eventBake_Parms, up), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SignedDistanceFieldBaker2D_eventBake_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_points_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_points,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_up,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker2D.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USignedDistanceFieldBaker2D, nullptr, "Bake", nullptr, nullptr, sizeof(SignedDistanceFieldBaker2D_eventBake_Parms), Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake_Statics::Function_MetaDataParams)) };
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_width_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_width;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_height_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_height;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExpandPercent_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ExpandPercent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_exportDir_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_exportDir;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_exportTexName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_exportTexName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DrawDebugInfo_MetaData[];
#endif
		static void NewProp_DrawDebugInfo_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_DrawDebugInfo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SDFBaker,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USignedDistanceFieldBaker2D_Bake, "Bake" }, // 3279103598
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SignedDistanceFieldBaker2D.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker2D.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_width_MetaData[] = {
		{ "Category", "SignedDistanceFieldBaker2D" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker2D.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_width = { "width", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USignedDistanceFieldBaker2D, width), METADATA_PARAMS(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_width_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_width_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_height_MetaData[] = {
		{ "Category", "SignedDistanceFieldBaker2D" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker2D.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_height = { "height", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USignedDistanceFieldBaker2D, height), METADATA_PARAMS(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_height_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_height_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_ExpandPercent_MetaData[] = {
		{ "Category", "SignedDistanceFieldBaker2D" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker2D.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_ExpandPercent = { "ExpandPercent", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USignedDistanceFieldBaker2D, ExpandPercent), METADATA_PARAMS(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_ExpandPercent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_ExpandPercent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_exportDir_MetaData[] = {
		{ "Category", "SignedDistanceFieldBaker2D" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker2D.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_exportDir = { "exportDir", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USignedDistanceFieldBaker2D, exportDir), METADATA_PARAMS(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_exportDir_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_exportDir_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_exportTexName_MetaData[] = {
		{ "Category", "SignedDistanceFieldBaker2D" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker2D.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_exportTexName = { "exportTexName", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USignedDistanceFieldBaker2D, exportTexName), METADATA_PARAMS(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_exportTexName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_exportTexName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_DrawDebugInfo_MetaData[] = {
		{ "Category", "SignedDistanceFieldBaker2D" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker2D.h" },
	};
#endif
	void Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_DrawDebugInfo_SetBit(void* Obj)
	{
		((USignedDistanceFieldBaker2D*)Obj)->DrawDebugInfo = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_DrawDebugInfo = { "DrawDebugInfo", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USignedDistanceFieldBaker2D), &Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_DrawDebugInfo_SetBit, METADATA_PARAMS(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_DrawDebugInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_DrawDebugInfo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_width,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_height,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_ExpandPercent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_exportDir,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_exportTexName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::NewProp_DrawDebugInfo,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USignedDistanceFieldBaker2D>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::ClassParams = {
		&USignedDistanceFieldBaker2D::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USignedDistanceFieldBaker2D_Statics::PropPointers),
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
	IMPLEMENT_CLASS(USignedDistanceFieldBaker2D, 2378237141);
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
