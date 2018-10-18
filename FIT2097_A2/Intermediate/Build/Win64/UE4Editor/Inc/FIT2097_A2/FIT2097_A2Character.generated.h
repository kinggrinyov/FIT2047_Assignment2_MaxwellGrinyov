// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AInteractableButton;
class AInteractableFuse;
class AInteractableKey;
class ADoor;
struct FVector;
#ifdef FIT2097_A2_FIT2097_A2Character_generated_h
#error "FIT2097_A2Character.generated.h already included, missing '#pragma once' in FIT2097_A2Character.h"
#endif
#define FIT2097_A2_FIT2097_A2Character_generated_h

#define FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_RPC_WRAPPERS \
	virtual bool CLIENT_ActivateButton_Validate(AInteractableButton* ); \
	virtual void CLIENT_ActivateButton_Implementation(AInteractableButton* button); \
	virtual bool CLIENT_PickupFuse_Validate(AInteractableFuse* ); \
	virtual void CLIENT_PickupFuse_Implementation(AInteractableFuse* fuseToPickup); \
	virtual bool CLIENT_PickupKey_Validate(AInteractableKey* ); \
	virtual void CLIENT_PickupKey_Implementation(AInteractableKey* keyToPickup); \
	virtual bool CLIENT_RequestOpenDoor_Validate(ADoor* , bool , bool ); \
	virtual void CLIENT_RequestOpenDoor_Implementation(ADoor* doorToOpen, bool haskey, bool hasfuse); \
	virtual bool CLIENT_SpawnExplosionAura_Validate(); \
	virtual void CLIENT_SpawnExplosionAura_Implementation(); \
	virtual void SERVER_SpawnExplosionAura_Implementation(); \
	virtual bool CLIENT_SpawnExplosion_Validate(FVector ); \
	virtual void CLIENT_SpawnExplosion_Implementation(FVector explodeLocation); \
	virtual void SERVER_SpawnExplosion_Implementation(FVector explodeLocation); \
 \
	DECLARE_FUNCTION(execCLIENT_ActivateButton) \
	{ \
		P_GET_OBJECT(AInteractableButton,Z_Param_button); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->CLIENT_ActivateButton_Validate(Z_Param_button)) \
		{ \
			RPC_ValidateFailed(TEXT("CLIENT_ActivateButton_Validate")); \
			return; \
		} \
		P_THIS->CLIENT_ActivateButton_Implementation(Z_Param_button); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCLIENT_PickupFuse) \
	{ \
		P_GET_OBJECT(AInteractableFuse,Z_Param_fuseToPickup); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->CLIENT_PickupFuse_Validate(Z_Param_fuseToPickup)) \
		{ \
			RPC_ValidateFailed(TEXT("CLIENT_PickupFuse_Validate")); \
			return; \
		} \
		P_THIS->CLIENT_PickupFuse_Implementation(Z_Param_fuseToPickup); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCLIENT_PickupKey) \
	{ \
		P_GET_OBJECT(AInteractableKey,Z_Param_keyToPickup); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->CLIENT_PickupKey_Validate(Z_Param_keyToPickup)) \
		{ \
			RPC_ValidateFailed(TEXT("CLIENT_PickupKey_Validate")); \
			return; \
		} \
		P_THIS->CLIENT_PickupKey_Implementation(Z_Param_keyToPickup); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCLIENT_RequestOpenDoor) \
	{ \
		P_GET_OBJECT(ADoor,Z_Param_doorToOpen); \
		P_GET_UBOOL(Z_Param_haskey); \
		P_GET_UBOOL(Z_Param_hasfuse); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->CLIENT_RequestOpenDoor_Validate(Z_Param_doorToOpen,Z_Param_haskey,Z_Param_hasfuse)) \
		{ \
			RPC_ValidateFailed(TEXT("CLIENT_RequestOpenDoor_Validate")); \
			return; \
		} \
		P_THIS->CLIENT_RequestOpenDoor_Implementation(Z_Param_doorToOpen,Z_Param_haskey,Z_Param_hasfuse); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCLIENT_SpawnExplosionAura) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->CLIENT_SpawnExplosionAura_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("CLIENT_SpawnExplosionAura_Validate")); \
			return; \
		} \
		P_THIS->CLIENT_SpawnExplosionAura_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSERVER_SpawnExplosionAura) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SERVER_SpawnExplosionAura_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCLIENT_SpawnExplosion) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_explodeLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->CLIENT_SpawnExplosion_Validate(Z_Param_explodeLocation)) \
		{ \
			RPC_ValidateFailed(TEXT("CLIENT_SpawnExplosion_Validate")); \
			return; \
		} \
		P_THIS->CLIENT_SpawnExplosion_Implementation(Z_Param_explodeLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSERVER_SpawnExplosion) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_explodeLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SERVER_SpawnExplosion_Implementation(Z_Param_explodeLocation); \
		P_NATIVE_END; \
	}


#define FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool CLIENT_ActivateButton_Validate(AInteractableButton* ); \
	virtual void CLIENT_ActivateButton_Implementation(AInteractableButton* button); \
	virtual bool CLIENT_PickupFuse_Validate(AInteractableFuse* ); \
	virtual void CLIENT_PickupFuse_Implementation(AInteractableFuse* fuseToPickup); \
	virtual bool CLIENT_PickupKey_Validate(AInteractableKey* ); \
	virtual void CLIENT_PickupKey_Implementation(AInteractableKey* keyToPickup); \
	virtual bool CLIENT_RequestOpenDoor_Validate(ADoor* , bool , bool ); \
	virtual void CLIENT_RequestOpenDoor_Implementation(ADoor* doorToOpen, bool haskey, bool hasfuse); \
	virtual bool CLIENT_SpawnExplosionAura_Validate(); \
	virtual void CLIENT_SpawnExplosionAura_Implementation(); \
	virtual void SERVER_SpawnExplosionAura_Implementation(); \
	virtual bool CLIENT_SpawnExplosion_Validate(FVector ); \
	virtual void CLIENT_SpawnExplosion_Implementation(FVector explodeLocation); \
	virtual void SERVER_SpawnExplosion_Implementation(FVector explodeLocation); \
 \
	DECLARE_FUNCTION(execCLIENT_ActivateButton) \
	{ \
		P_GET_OBJECT(AInteractableButton,Z_Param_button); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->CLIENT_ActivateButton_Validate(Z_Param_button)) \
		{ \
			RPC_ValidateFailed(TEXT("CLIENT_ActivateButton_Validate")); \
			return; \
		} \
		P_THIS->CLIENT_ActivateButton_Implementation(Z_Param_button); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCLIENT_PickupFuse) \
	{ \
		P_GET_OBJECT(AInteractableFuse,Z_Param_fuseToPickup); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->CLIENT_PickupFuse_Validate(Z_Param_fuseToPickup)) \
		{ \
			RPC_ValidateFailed(TEXT("CLIENT_PickupFuse_Validate")); \
			return; \
		} \
		P_THIS->CLIENT_PickupFuse_Implementation(Z_Param_fuseToPickup); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCLIENT_PickupKey) \
	{ \
		P_GET_OBJECT(AInteractableKey,Z_Param_keyToPickup); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->CLIENT_PickupKey_Validate(Z_Param_keyToPickup)) \
		{ \
			RPC_ValidateFailed(TEXT("CLIENT_PickupKey_Validate")); \
			return; \
		} \
		P_THIS->CLIENT_PickupKey_Implementation(Z_Param_keyToPickup); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCLIENT_RequestOpenDoor) \
	{ \
		P_GET_OBJECT(ADoor,Z_Param_doorToOpen); \
		P_GET_UBOOL(Z_Param_haskey); \
		P_GET_UBOOL(Z_Param_hasfuse); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->CLIENT_RequestOpenDoor_Validate(Z_Param_doorToOpen,Z_Param_haskey,Z_Param_hasfuse)) \
		{ \
			RPC_ValidateFailed(TEXT("CLIENT_RequestOpenDoor_Validate")); \
			return; \
		} \
		P_THIS->CLIENT_RequestOpenDoor_Implementation(Z_Param_doorToOpen,Z_Param_haskey,Z_Param_hasfuse); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCLIENT_SpawnExplosionAura) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->CLIENT_SpawnExplosionAura_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("CLIENT_SpawnExplosionAura_Validate")); \
			return; \
		} \
		P_THIS->CLIENT_SpawnExplosionAura_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSERVER_SpawnExplosionAura) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SERVER_SpawnExplosionAura_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCLIENT_SpawnExplosion) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_explodeLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->CLIENT_SpawnExplosion_Validate(Z_Param_explodeLocation)) \
		{ \
			RPC_ValidateFailed(TEXT("CLIENT_SpawnExplosion_Validate")); \
			return; \
		} \
		P_THIS->CLIENT_SpawnExplosion_Implementation(Z_Param_explodeLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSERVER_SpawnExplosion) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_explodeLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SERVER_SpawnExplosion_Implementation(Z_Param_explodeLocation); \
		P_NATIVE_END; \
	}


#define FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_EVENT_PARMS \
	struct FIT2097_A2Character_eventCLIENT_ActivateButton_Parms \
	{ \
		AInteractableButton* button; \
	}; \
	struct FIT2097_A2Character_eventCLIENT_PickupFuse_Parms \
	{ \
		AInteractableFuse* fuseToPickup; \
	}; \
	struct FIT2097_A2Character_eventCLIENT_PickupKey_Parms \
	{ \
		AInteractableKey* keyToPickup; \
	}; \
	struct FIT2097_A2Character_eventCLIENT_RequestOpenDoor_Parms \
	{ \
		ADoor* doorToOpen; \
		bool haskey; \
		bool hasfuse; \
	}; \
	struct FIT2097_A2Character_eventCLIENT_SpawnExplosion_Parms \
	{ \
		FVector explodeLocation; \
	}; \
	struct FIT2097_A2Character_eventSERVER_SpawnExplosion_Parms \
	{ \
		FVector explodeLocation; \
	};


#define FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_CALLBACK_WRAPPERS
#define FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFIT2097_A2Character(); \
	friend FIT2097_A2_API class UClass* Z_Construct_UClass_AFIT2097_A2Character(); \
public: \
	DECLARE_CLASS(AFIT2097_A2Character, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FIT2097_A2"), NO_API) \
	DECLARE_SERIALIZER(AFIT2097_A2Character) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAFIT2097_A2Character(); \
	friend FIT2097_A2_API class UClass* Z_Construct_UClass_AFIT2097_A2Character(); \
public: \
	DECLARE_CLASS(AFIT2097_A2Character, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FIT2097_A2"), NO_API) \
	DECLARE_SERIALIZER(AFIT2097_A2Character) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFIT2097_A2Character(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFIT2097_A2Character) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFIT2097_A2Character); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFIT2097_A2Character); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFIT2097_A2Character(AFIT2097_A2Character&&); \
	NO_API AFIT2097_A2Character(const AFIT2097_A2Character&); \
public:


#define FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFIT2097_A2Character(AFIT2097_A2Character&&); \
	NO_API AFIT2097_A2Character(const AFIT2097_A2Character&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFIT2097_A2Character); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFIT2097_A2Character); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFIT2097_A2Character)


#define FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AFIT2097_A2Character, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AFIT2097_A2Character, FollowCamera); }


#define FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_13_PROLOG \
	FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_EVENT_PARMS


#define FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_PRIVATE_PROPERTY_OFFSET \
	FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_RPC_WRAPPERS \
	FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_CALLBACK_WRAPPERS \
	FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_INCLASS \
	FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_PRIVATE_PROPERTY_OFFSET \
	FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_CALLBACK_WRAPPERS \
	FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_INCLASS_NO_PURE_DECLS \
	FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FIT2097_A2_Source_FIT2097_A2_FIT2097_A2Character_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
