// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MathLib/Public/UnitTest/MathLibActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMathLibActor() {}
// Cross Module References
	MATHLIB_API UClass* Z_Construct_UClass_AMathLibActor_NoRegister();
	MATHLIB_API UClass* Z_Construct_UClass_AMathLibActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MathLib();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(AMathLibActor::execConvex)
	{
		P_GET_TARRAY(FVector,Z_Param_points);
		P_GET_STRUCT(FVector,Z_Param_o);
		P_GET_STRUCT(FVector,Z_Param_on);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FVector>*)Z_Param__Result=P_THIS->Convex(Z_Param_points,Z_Param_o,Z_Param_on);
		P_NATIVE_END;
	}
	void AMathLibActor::StaticRegisterNativesAMathLibActor()
	{
		UClass* Class = AMathLibActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Convex", &AMathLibActor::execConvex },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMathLibActor_Convex_Statics
	{
		struct MathLibActor_eventConvex_Parms
		{
			TArray<FVector> points;
			FVector o;
			FVector on;
			TArray<FVector> ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_points_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_points;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_o;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_on;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMathLibActor_Convex_Statics::NewProp_points_Inner = { "points", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMathLibActor_Convex_Statics::NewProp_points = { "points", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventConvex_Parms, points), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMathLibActor_Convex_Statics::NewProp_o = { "o", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventConvex_Parms, o), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMathLibActor_Convex_Statics::NewProp_on = { "on", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventConvex_Parms, on), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMathLibActor_Convex_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMathLibActor_Convex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventConvex_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMathLibActor_Convex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_Convex_Statics::NewProp_points_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_Convex_Statics::NewProp_points,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_Convex_Statics::NewProp_o,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_Convex_Statics::NewProp_on,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_Convex_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_Convex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMathLibActor_Convex_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UnitTest/MathLibActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMathLibActor_Convex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMathLibActor, nullptr, "Convex", nullptr, nullptr, sizeof(MathLibActor_eventConvex_Parms), Z_Construct_UFunction_AMathLibActor_Convex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMathLibActor_Convex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMathLibActor_Convex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMathLibActor_Convex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMathLibActor_Convex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMathLibActor_Convex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMathLibActor_NoRegister()
	{
		return AMathLibActor::StaticClass();
	}
	struct Z_Construct_UClass_AMathLibActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMathLibActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MathLib,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMathLibActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMathLibActor_Convex, "Convex" }, // 2307024596
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMathLibActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "UnitTest/MathLibActor.h" },
		{ "ModuleRelativePath", "Public/UnitTest/MathLibActor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMathLibActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMathLibActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMathLibActor_Statics::ClassParams = {
		&AMathLibActor::StaticClass,
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
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMathLibActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMathLibActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMathLibActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMathLibActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMathLibActor, 3357314115);
	template<> MATHLIB_API UClass* StaticClass<AMathLibActor>()
	{
		return AMathLibActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMathLibActor(Z_Construct_UClass_AMathLibActor, &AMathLibActor::StaticClass, TEXT("/Script/MathLib"), TEXT("AMathLibActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMathLibActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
