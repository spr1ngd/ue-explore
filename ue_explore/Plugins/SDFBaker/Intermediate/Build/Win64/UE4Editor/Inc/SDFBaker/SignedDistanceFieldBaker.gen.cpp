// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SDFBaker/Public/SignedDistanceFieldBaker.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSignedDistanceFieldBaker() {}
// Cross Module References
	SDFBAKER_API UClass* Z_Construct_UClass_ASignedDistanceFieldBaker_NoRegister();
	SDFBAKER_API UClass* Z_Construct_UClass_ASignedDistanceFieldBaker();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor();
	UPackage* Z_Construct_UPackage__Script_SDFBaker();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(ASignedDistanceFieldBaker::execVisualizeVolume)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->VisualizeVolume();
		P_NATIVE_END;
	}
	void ASignedDistanceFieldBaker::StaticRegisterNativesASignedDistanceFieldBaker()
	{
		UClass* Class = ASignedDistanceFieldBaker::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "VisualizeVolume", &ASignedDistanceFieldBaker::execVisualizeVolume },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASignedDistanceFieldBaker_VisualizeVolume_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASignedDistanceFieldBaker_VisualizeVolume_Statics::Function_MetaDataParams[] = {
		{ "Category", "SDF" },
		{ "Comment", "// visualize aabb \n// visualize voxel of volume texture\n" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker.h" },
		{ "ToolTip", "visualize aabb\nvisualize voxel of volume texture" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASignedDistanceFieldBaker_VisualizeVolume_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASignedDistanceFieldBaker, nullptr, "VisualizeVolume", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASignedDistanceFieldBaker_VisualizeVolume_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASignedDistanceFieldBaker_VisualizeVolume_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASignedDistanceFieldBaker_VisualizeVolume()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASignedDistanceFieldBaker_VisualizeVolume_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASignedDistanceFieldBaker_NoRegister()
	{
		return ASignedDistanceFieldBaker::StaticClass();
	}
	struct Z_Construct_UClass_ASignedDistanceFieldBaker_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DrawDebugInfo_MetaData[];
#endif
		static void NewProp_DrawDebugInfo_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_DrawDebugInfo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UseTickInEditor_MetaData[];
#endif
		static void NewProp_UseTickInEditor_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_UseTickInEditor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DebugLineWidth_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DebugLineWidth;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VoxelSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VoxelSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VolumeIncreasePercent_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VolumeIncreasePercent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VolumeTextureSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_VolumeTextureSize;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AStaticMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SDFBaker,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASignedDistanceFieldBaker_VisualizeVolume, "VisualizeVolume" }, // 2769748823
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "SignedDistanceFieldBaker.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_DrawDebugInfo_MetaData[] = {
		{ "Category", "SDF.Debug" },
		{ "Comment", "// editor debug\n" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker.h" },
		{ "ToolTip", "editor debug" },
	};
#endif
	void Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_DrawDebugInfo_SetBit(void* Obj)
	{
		((ASignedDistanceFieldBaker*)Obj)->DrawDebugInfo = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_DrawDebugInfo = { "DrawDebugInfo", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASignedDistanceFieldBaker), &Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_DrawDebugInfo_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_DrawDebugInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_DrawDebugInfo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_UseTickInEditor_MetaData[] = {
		{ "Category", "SDF.Debug" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker.h" },
	};
#endif
	void Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_UseTickInEditor_SetBit(void* Obj)
	{
		((ASignedDistanceFieldBaker*)Obj)->UseTickInEditor = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_UseTickInEditor = { "UseTickInEditor", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASignedDistanceFieldBaker), &Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_UseTickInEditor_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_UseTickInEditor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_UseTickInEditor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_DebugLineWidth_MetaData[] = {
		{ "Category", "SDF.Debug" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_DebugLineWidth = { "DebugLineWidth", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASignedDistanceFieldBaker, DebugLineWidth), METADATA_PARAMS(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_DebugLineWidth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_DebugLineWidth_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VoxelSize_MetaData[] = {
		{ "Category", "SDF.Debug" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VoxelSize = { "VoxelSize", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASignedDistanceFieldBaker, VoxelSize), METADATA_PARAMS(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VoxelSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VoxelSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VolumeIncreasePercent_MetaData[] = {
		{ "Category", "SDF" },
		{ "Comment", "// runtime \n" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker.h" },
		{ "ToolTip", "runtime" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VolumeIncreasePercent = { "VolumeIncreasePercent", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASignedDistanceFieldBaker, VolumeIncreasePercent), METADATA_PARAMS(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VolumeIncreasePercent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VolumeIncreasePercent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VolumeTextureSize_MetaData[] = {
		{ "Category", "SDF" },
		{ "ModuleRelativePath", "Public/SignedDistanceFieldBaker.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VolumeTextureSize = { "VolumeTextureSize", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASignedDistanceFieldBaker, VolumeTextureSize), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VolumeTextureSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VolumeTextureSize_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_DrawDebugInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_UseTickInEditor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_DebugLineWidth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VoxelSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VolumeIncreasePercent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::NewProp_VolumeTextureSize,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASignedDistanceFieldBaker>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::ClassParams = {
		&ASignedDistanceFieldBaker::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASignedDistanceFieldBaker()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASignedDistanceFieldBaker_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASignedDistanceFieldBaker, 228506175);
	template<> SDFBAKER_API UClass* StaticClass<ASignedDistanceFieldBaker>()
	{
		return ASignedDistanceFieldBaker::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASignedDistanceFieldBaker(Z_Construct_UClass_ASignedDistanceFieldBaker, &ASignedDistanceFieldBaker::StaticClass, TEXT("/Script/SDFBaker"), TEXT("ASignedDistanceFieldBaker"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASignedDistanceFieldBaker);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
