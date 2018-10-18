// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "FIT2097_A2Character.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFIT2097_A2Character() {}
// Cross Module References
	FIT2097_A2_API UClass* Z_Construct_UClass_AFIT2097_A2Character_NoRegister();
	FIT2097_A2_API UClass* Z_Construct_UClass_AFIT2097_A2Character();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_FIT2097_A2();
	FIT2097_A2_API UFunction* Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_ActivateButton();
	FIT2097_A2_API UClass* Z_Construct_UClass_AInteractableButton_NoRegister();
	FIT2097_A2_API UFunction* Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_PickupFuse();
	FIT2097_A2_API UClass* Z_Construct_UClass_AInteractableFuse_NoRegister();
	FIT2097_A2_API UFunction* Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_PickupKey();
	FIT2097_A2_API UClass* Z_Construct_UClass_AInteractableKey_NoRegister();
	FIT2097_A2_API UFunction* Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_RequestOpenDoor();
	FIT2097_A2_API UClass* Z_Construct_UClass_ADoor_NoRegister();
	FIT2097_A2_API UFunction* Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_SpawnExplosion();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	FIT2097_A2_API UFunction* Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_SpawnExplosionAura();
	FIT2097_A2_API UFunction* Z_Construct_UFunction_AFIT2097_A2Character_SERVER_SpawnExplosion();
	FIT2097_A2_API UFunction* Z_Construct_UFunction_AFIT2097_A2Character_SERVER_SpawnExplosionAura();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundCue_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	static FName NAME_AFIT2097_A2Character_CLIENT_ActivateButton = FName(TEXT("CLIENT_ActivateButton"));
	void AFIT2097_A2Character::CLIENT_ActivateButton(AInteractableButton* button)
	{
		FIT2097_A2Character_eventCLIENT_ActivateButton_Parms Parms;
		Parms.button=button;
		ProcessEvent(FindFunctionChecked(NAME_AFIT2097_A2Character_CLIENT_ActivateButton),&Parms);
	}
	static FName NAME_AFIT2097_A2Character_CLIENT_PickupFuse = FName(TEXT("CLIENT_PickupFuse"));
	void AFIT2097_A2Character::CLIENT_PickupFuse(AInteractableFuse* fuseToPickup)
	{
		FIT2097_A2Character_eventCLIENT_PickupFuse_Parms Parms;
		Parms.fuseToPickup=fuseToPickup;
		ProcessEvent(FindFunctionChecked(NAME_AFIT2097_A2Character_CLIENT_PickupFuse),&Parms);
	}
	static FName NAME_AFIT2097_A2Character_CLIENT_PickupKey = FName(TEXT("CLIENT_PickupKey"));
	void AFIT2097_A2Character::CLIENT_PickupKey(AInteractableKey* keyToPickup)
	{
		FIT2097_A2Character_eventCLIENT_PickupKey_Parms Parms;
		Parms.keyToPickup=keyToPickup;
		ProcessEvent(FindFunctionChecked(NAME_AFIT2097_A2Character_CLIENT_PickupKey),&Parms);
	}
	static FName NAME_AFIT2097_A2Character_CLIENT_RequestOpenDoor = FName(TEXT("CLIENT_RequestOpenDoor"));
	void AFIT2097_A2Character::CLIENT_RequestOpenDoor(ADoor* doorToOpen, bool haskey, bool hasfuse)
	{
		FIT2097_A2Character_eventCLIENT_RequestOpenDoor_Parms Parms;
		Parms.doorToOpen=doorToOpen;
		Parms.haskey=haskey ? true : false;
		Parms.hasfuse=hasfuse ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AFIT2097_A2Character_CLIENT_RequestOpenDoor),&Parms);
	}
	static FName NAME_AFIT2097_A2Character_CLIENT_SpawnExplosion = FName(TEXT("CLIENT_SpawnExplosion"));
	void AFIT2097_A2Character::CLIENT_SpawnExplosion(FVector explodeLocation)
	{
		FIT2097_A2Character_eventCLIENT_SpawnExplosion_Parms Parms;
		Parms.explodeLocation=explodeLocation;
		ProcessEvent(FindFunctionChecked(NAME_AFIT2097_A2Character_CLIENT_SpawnExplosion),&Parms);
	}
	static FName NAME_AFIT2097_A2Character_CLIENT_SpawnExplosionAura = FName(TEXT("CLIENT_SpawnExplosionAura"));
	void AFIT2097_A2Character::CLIENT_SpawnExplosionAura()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFIT2097_A2Character_CLIENT_SpawnExplosionAura),NULL);
	}
	static FName NAME_AFIT2097_A2Character_SERVER_SpawnExplosion = FName(TEXT("SERVER_SpawnExplosion"));
	void AFIT2097_A2Character::SERVER_SpawnExplosion(FVector explodeLocation)
	{
		FIT2097_A2Character_eventSERVER_SpawnExplosion_Parms Parms;
		Parms.explodeLocation=explodeLocation;
		ProcessEvent(FindFunctionChecked(NAME_AFIT2097_A2Character_SERVER_SpawnExplosion),&Parms);
	}
	static FName NAME_AFIT2097_A2Character_SERVER_SpawnExplosionAura = FName(TEXT("SERVER_SpawnExplosionAura"));
	void AFIT2097_A2Character::SERVER_SpawnExplosionAura()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFIT2097_A2Character_SERVER_SpawnExplosionAura),NULL);
	}
	void AFIT2097_A2Character::StaticRegisterNativesAFIT2097_A2Character()
	{
		UClass* Class = AFIT2097_A2Character::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CLIENT_ActivateButton", &AFIT2097_A2Character::execCLIENT_ActivateButton },
			{ "CLIENT_PickupFuse", &AFIT2097_A2Character::execCLIENT_PickupFuse },
			{ "CLIENT_PickupKey", &AFIT2097_A2Character::execCLIENT_PickupKey },
			{ "CLIENT_RequestOpenDoor", &AFIT2097_A2Character::execCLIENT_RequestOpenDoor },
			{ "CLIENT_SpawnExplosion", &AFIT2097_A2Character::execCLIENT_SpawnExplosion },
			{ "CLIENT_SpawnExplosionAura", &AFIT2097_A2Character::execCLIENT_SpawnExplosionAura },
			{ "SERVER_SpawnExplosion", &AFIT2097_A2Character::execSERVER_SpawnExplosion },
			{ "SERVER_SpawnExplosionAura", &AFIT2097_A2Character::execSERVER_SpawnExplosionAura },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_ActivateButton()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_button = { UE4CodeGen_Private::EPropertyClass::Object, "button", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FIT2097_A2Character_eventCLIENT_ActivateButton_Parms, button), Z_Construct_UClass_AInteractableButton_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_button,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFIT2097_A2Character, "CLIENT_ActivateButton", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x80220CC0, sizeof(FIT2097_A2Character_eventCLIENT_ActivateButton_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_PickupFuse()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_fuseToPickup = { UE4CodeGen_Private::EPropertyClass::Object, "fuseToPickup", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FIT2097_A2Character_eventCLIENT_PickupFuse_Parms, fuseToPickup), Z_Construct_UClass_AInteractableFuse_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_fuseToPickup,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFIT2097_A2Character, "CLIENT_PickupFuse", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x80220CC0, sizeof(FIT2097_A2Character_eventCLIENT_PickupFuse_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_PickupKey()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_keyToPickup = { UE4CodeGen_Private::EPropertyClass::Object, "keyToPickup", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FIT2097_A2Character_eventCLIENT_PickupKey_Parms, keyToPickup), Z_Construct_UClass_AInteractableKey_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_keyToPickup,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFIT2097_A2Character, "CLIENT_PickupKey", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x80220CC0, sizeof(FIT2097_A2Character_eventCLIENT_PickupKey_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_RequestOpenDoor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_hasfuse_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			auto NewProp_hasfuse_SetBit = [](void* Obj){ ((FIT2097_A2Character_eventCLIENT_RequestOpenDoor_Parms*)Obj)->hasfuse = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_hasfuse = { UE4CodeGen_Private::EPropertyClass::Bool, "hasfuse", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FIT2097_A2Character_eventCLIENT_RequestOpenDoor_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_hasfuse_SetBit)>::SetBit, METADATA_PARAMS(NewProp_hasfuse_MetaData, ARRAY_COUNT(NewProp_hasfuse_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_haskey_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			auto NewProp_haskey_SetBit = [](void* Obj){ ((FIT2097_A2Character_eventCLIENT_RequestOpenDoor_Parms*)Obj)->haskey = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_haskey = { UE4CodeGen_Private::EPropertyClass::Bool, "haskey", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FIT2097_A2Character_eventCLIENT_RequestOpenDoor_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_haskey_SetBit)>::SetBit, METADATA_PARAMS(NewProp_haskey_MetaData, ARRAY_COUNT(NewProp_haskey_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_doorToOpen = { UE4CodeGen_Private::EPropertyClass::Object, "doorToOpen", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FIT2097_A2Character_eventCLIENT_RequestOpenDoor_Parms, doorToOpen), Z_Construct_UClass_ADoor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_hasfuse,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_haskey,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_doorToOpen,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFIT2097_A2Character, "CLIENT_RequestOpenDoor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x80220CC0, sizeof(FIT2097_A2Character_eventCLIENT_RequestOpenDoor_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_SpawnExplosion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_explodeLocation = { UE4CodeGen_Private::EPropertyClass::Struct, "explodeLocation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FIT2097_A2Character_eventCLIENT_SpawnExplosion_Parms, explodeLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_explodeLocation,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFIT2097_A2Character, "CLIENT_SpawnExplosion", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x80A20CC0, sizeof(FIT2097_A2Character_eventCLIENT_SpawnExplosion_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_SpawnExplosionAura()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFIT2097_A2Character, "CLIENT_SpawnExplosionAura", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x80220CC0, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFIT2097_A2Character_SERVER_SpawnExplosion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_explodeLocation = { UE4CodeGen_Private::EPropertyClass::Struct, "explodeLocation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FIT2097_A2Character_eventSERVER_SpawnExplosion_Parms, explodeLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_explodeLocation,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFIT2097_A2Character, "SERVER_SpawnExplosion", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00824CC0, sizeof(FIT2097_A2Character_eventSERVER_SpawnExplosion_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFIT2097_A2Character_SERVER_SpawnExplosionAura()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFIT2097_A2Character, "SERVER_SpawnExplosionAura", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00024CC0, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFIT2097_A2Character_NoRegister()
	{
		return AFIT2097_A2Character::StaticClass();
	}
	UClass* Z_Construct_UClass_AFIT2097_A2Character()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ACharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_FIT2097_A2,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_ActivateButton, "CLIENT_ActivateButton" }, // 1945773055
				{ &Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_PickupFuse, "CLIENT_PickupFuse" }, // 4290985563
				{ &Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_PickupKey, "CLIENT_PickupKey" }, // 2097115308
				{ &Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_RequestOpenDoor, "CLIENT_RequestOpenDoor" }, // 2196546938
				{ &Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_SpawnExplosion, "CLIENT_SpawnExplosion" }, // 495656164
				{ &Z_Construct_UFunction_AFIT2097_A2Character_CLIENT_SpawnExplosionAura, "CLIENT_SpawnExplosionAura" }, // 1650329174
				{ &Z_Construct_UFunction_AFIT2097_A2Character_SERVER_SpawnExplosion, "SERVER_SpawnExplosion" }, // 4096777594
				{ &Z_Construct_UFunction_AFIT2097_A2Character_SERVER_SpawnExplosionAura, "SERVER_SpawnExplosionAura" }, // 724888317
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "FIT2097_A2Character.h" },
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExplosionModeAura_MetaData[] = {
				{ "Category", "VFX" },
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ExplosionModeAura = { UE4CodeGen_Private::EPropertyClass::Object, "ExplosionModeAura", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AFIT2097_A2Character, ExplosionModeAura), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(NewProp_ExplosionModeAura_MetaData, ARRAY_COUNT(NewProp_ExplosionModeAura_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExplosionSFX_MetaData[] = {
				{ "Category", "SFX" },
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ExplosionSFX = { UE4CodeGen_Private::EPropertyClass::Object, "ExplosionSFX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AFIT2097_A2Character, ExplosionSFX), Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(NewProp_ExplosionSFX_MetaData, ARRAY_COUNT(NewProp_ExplosionSFX_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExplosionEffect_MetaData[] = {
				{ "Category", "VFX" },
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
				{ "ToolTip", "MyStuff" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ExplosionEffect = { UE4CodeGen_Private::EPropertyClass::Object, "ExplosionEffect", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AFIT2097_A2Character, ExplosionEffect), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(NewProp_ExplosionEffect_MetaData, ARRAY_COUNT(NewProp_ExplosionEffect_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[] = {
				{ "Category", "Camera" },
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
				{ "ToolTip", "Base look up/down rate, in deg/sec. Other scaling may affect final rate." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate = { UE4CodeGen_Private::EPropertyClass::Float, "BaseLookUpRate", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000020015, 1, nullptr, STRUCT_OFFSET(AFIT2097_A2Character, BaseLookUpRate), METADATA_PARAMS(NewProp_BaseLookUpRate_MetaData, ARRAY_COUNT(NewProp_BaseLookUpRate_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[] = {
				{ "Category", "Camera" },
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
				{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate = { UE4CodeGen_Private::EPropertyClass::Float, "BaseTurnRate", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000020015, 1, nullptr, STRUCT_OFFSET(AFIT2097_A2Character, BaseTurnRate), METADATA_PARAMS(NewProp_BaseTurnRate_MetaData, ARRAY_COUNT(NewProp_BaseTurnRate_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
				{ "ToolTip", "Follow camera" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FollowCamera = { UE4CodeGen_Private::EPropertyClass::Object, "FollowCamera", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(AFIT2097_A2Character, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(NewProp_FollowCamera_MetaData, ARRAY_COUNT(NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "FIT2097_A2Character.h" },
				{ "ToolTip", "Camera boom positioning the camera behind the character" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom = { UE4CodeGen_Private::EPropertyClass::Object, "CameraBoom", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(AFIT2097_A2Character, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(NewProp_CameraBoom_MetaData, ARRAY_COUNT(NewProp_CameraBoom_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ExplosionModeAura,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ExplosionSFX,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ExplosionEffect,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BaseLookUpRate,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BaseTurnRate,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FollowCamera,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CameraBoom,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AFIT2097_A2Character>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AFIT2097_A2Character::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00800080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				"Game",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFIT2097_A2Character, 1527281179);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFIT2097_A2Character(Z_Construct_UClass_AFIT2097_A2Character, &AFIT2097_A2Character::StaticClass, TEXT("/Script/FIT2097_A2"), TEXT("AFIT2097_A2Character"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFIT2097_A2Character);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
