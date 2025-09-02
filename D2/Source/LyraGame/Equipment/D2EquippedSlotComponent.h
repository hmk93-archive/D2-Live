// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Components/ControllerComponent.h"
#include "Inventory/LyraInventoryItemInstance.h"

#include "D2EquippedSlotComponent.generated.h"

class AActor;
class ULyraEquipmentInstance;
class ULyraEquipmentManagerComponent;
class UObject;
struct FFrame;


/*
 *	ED2EquippedSlotKey
 * 
 *	- Slots 의 Key 값을 관리
 */
UENUM()
enum class ED2EquippedSlotKey : uint8
{
	Torso,
	Legs,
	Shoes,
	Accessory,
	Count
};


/*
 *	UD2EquippedSlotComponent
 *  
 *	@TODO: 현재는 해당 컴포넌트를 사용하지 않고 블루프린트에서 구현함
 */
UCLASS(Blueprintable, meta=(BlueprintSpawnableComponent))
class UD2EquippedSlotComponent : public UControllerComponent
{
	GENERATED_BODY()

public:

	UD2EquippedSlotComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddItemToSlot(FGameplayTag Tag, ULyraInventoryItemInstance* Item);

protected:

	UFUNCTION()
	void OnRep_Slots();

	int32 FindKeyFromTag(FGameplayTag Tag);

private:

	UPROPERTY(ReplicatedUsing=OnRep_Slots)
	TArray<TObjectPtr<ULyraInventoryItemInstance>> Slots;
};
