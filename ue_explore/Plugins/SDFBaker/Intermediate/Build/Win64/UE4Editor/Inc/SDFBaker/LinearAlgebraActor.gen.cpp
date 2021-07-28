// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SDFBaker/Public/UnitTest/LinearAlgebraActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLinearAlgebraActor() {}
// Cross Module References
	SDFBAKER_API UClass* Z_Construct_UClass_ALinearAlgebraActor_NoRegister();
	SDFBAKER_API UClass* Z_Construct_UClass_ALinearAlgebraActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SDFBaker();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(ALinearAlgebraActor::execDrawClosestDistance)
	{
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_SMC);
		P_GET_STRUCT(FVector,Z_Param_point);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DrawClosestDistance(Z_Param_SMC,Z_Param_point);
		P_NATIVE_END;
	}
	void ALinearAlgebraActor::StaticRegisterNativesALinearAlgebraActor()
	{
		UClass* Class = ALinearAlgebraActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DrawClosestDistance", &ALinearAlgebraActor::execDrawClosestDistance },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics
	{
		struct LinearAlgebraActor_eventDrawClosestDistance_Parms
		{
			UStaticMeshComponent* SMC;
			FVector point;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SMC_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SMC;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_point;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::NewProp_SMC_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::NewProp_SMC = { "SMC", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LinearAlgebraActor_eventDrawClosestDistance_Parms, SMC), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::NewProp_SMC_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::NewProp_SMC_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::NewProp_point = { "point", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LinearAlgebraActor_eventDrawClosestDistance_Parms, point), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::NewProp_SMC,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::NewProp_point,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UnitTest/LinearAlgebraActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALinearAlgebraActor, nullptr, "DrawClosestDistance", nullptr, nullptr, sizeof(LinearAlgebraActor_eventDrawClosestDistance_Parms), Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ALinearAlgebraActor_NoRegister()
	{
		return ALinearAlgebraActor::StaticClass();
	}
	struct Z_Construct_UClass_ALinearAlgebraActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALinearAlgebraActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SDFBaker,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ALinearAlgebraActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ALinearAlgebraActor_DrawClosestDistance, "DrawClosestDistance" }, // 916687339
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALinearAlgebraActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "UnitTest/LinearAlgebraActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UnitTest/LinearAlgebraActor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALinearAlgebraActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALinearAlgebraActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALinearAlgebraActor_Statics::ClassParams = {
		&ALinearAlgebraActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ALinearAlgebraActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALinearAlgebraActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALinearAlgebraActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALinearAlgebraActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALinearAlgebraActor, 3499609908);
	template<> SDFBAKER_API UClass* StaticClass<ALinearAlgebraActor>()
	{
		return ALinearAlgebraActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALinearAlgebraActor(Z_Construct_UClass_ALinearAlgebraActor, &ALinearAlgebraActor::StaticClass, TEXT("/Script/SDFBaker"), TEXT("ALinearAlgebraActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALinearAlgebraActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
