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
	DEFINE_FUNCTION(AMathLibActor::execRaySphere)
	{
		P_GET_STRUCT(FVector,Z_Param_ro);
		P_GET_STRUCT(FVector,Z_Param_rd);
		P_GET_STRUCT(FVector,Z_Param_center);
		P_GET_PROPERTY(FFloatProperty,Z_Param_radius);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_minDist);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_maxDist);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RaySphere(Z_Param_ro,Z_Param_rd,Z_Param_center,Z_Param_radius,Z_Param_Out_minDist,Z_Param_Out_maxDist);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMathLibActor::execRayBox)
	{
		P_GET_STRUCT(FVector,Z_Param_ro);
		P_GET_STRUCT(FVector,Z_Param_rd);
		P_GET_STRUCT(FVector,Z_Param_boundMin);
		P_GET_STRUCT(FVector,Z_Param_boundMax);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_minDist);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_maxDist);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RayBox(Z_Param_ro,Z_Param_rd,Z_Param_boundMin,Z_Param_boundMax,Z_Param_Out_minDist,Z_Param_Out_maxDist);
		P_NATIVE_END;
	}
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
			{ "RayBox", &AMathLibActor::execRayBox },
			{ "RaySphere", &AMathLibActor::execRaySphere },
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
	struct Z_Construct_UFunction_AMathLibActor_RayBox_Statics
	{
		struct MathLibActor_eventRayBox_Parms
		{
			FVector ro;
			FVector rd;
			FVector boundMin;
			FVector boundMax;
			float minDist;
			float maxDist;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ro;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_rd;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_boundMin;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_boundMax;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_minDist;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_maxDist;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_ro = { "ro", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventRayBox_Parms, ro), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_rd = { "rd", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventRayBox_Parms, rd), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_boundMin = { "boundMin", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventRayBox_Parms, boundMin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_boundMax = { "boundMax", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventRayBox_Parms, boundMax), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_minDist = { "minDist", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventRayBox_Parms, minDist), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_maxDist = { "maxDist", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventRayBox_Parms, maxDist), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MathLibActor_eventRayBox_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MathLibActor_eventRayBox_Parms), &Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMathLibActor_RayBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_ro,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_rd,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_boundMin,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_boundMax,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_minDist,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_maxDist,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RayBox_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMathLibActor_RayBox_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// intersection\n" },
		{ "ModuleRelativePath", "Public/UnitTest/MathLibActor.h" },
		{ "ToolTip", "intersection" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMathLibActor_RayBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMathLibActor, nullptr, "RayBox", nullptr, nullptr, sizeof(MathLibActor_eventRayBox_Parms), Z_Construct_UFunction_AMathLibActor_RayBox_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMathLibActor_RayBox_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMathLibActor_RayBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMathLibActor_RayBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMathLibActor_RayBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMathLibActor_RayBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMathLibActor_RaySphere_Statics
	{
		struct MathLibActor_eventRaySphere_Parms
		{
			FVector ro;
			FVector rd;
			FVector center;
			float radius;
			float minDist;
			float maxDist;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ro;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_rd;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_center;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radius;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_minDist;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_maxDist;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_ro = { "ro", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventRaySphere_Parms, ro), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_rd = { "rd", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventRaySphere_Parms, rd), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_center = { "center", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventRaySphere_Parms, center), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_radius = { "radius", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventRaySphere_Parms, radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_minDist = { "minDist", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventRaySphere_Parms, minDist), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_maxDist = { "maxDist", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathLibActor_eventRaySphere_Parms, maxDist), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MathLibActor_eventRaySphere_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MathLibActor_eventRaySphere_Parms), &Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_ro,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_rd,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_center,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_minDist,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_maxDist,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UnitTest/MathLibActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMathLibActor, nullptr, "RaySphere", nullptr, nullptr, sizeof(MathLibActor_eventRaySphere_Parms), Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMathLibActor_RaySphere()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMathLibActor_RaySphere_Statics::FuncParams);
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
		{ &Z_Construct_UFunction_AMathLibActor_RayBox, "RayBox" }, // 455321162
		{ &Z_Construct_UFunction_AMathLibActor_RaySphere, "RaySphere" }, // 4090011508
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
	IMPLEMENT_CLASS(AMathLibActor, 2454664384);
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
