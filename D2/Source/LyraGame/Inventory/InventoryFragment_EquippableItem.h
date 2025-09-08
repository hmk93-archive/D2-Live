// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Inventory/LyraInventoryItemDefinition.h"
#include "Templates/SubclassOf.h"

#include "InventoryFragment_EquippableItem.generated.h"

class ULyraEquipmentDefinition;
class UObject;

UCLASS()
class UInventoryFragment_EquippableItem : public ULyraInventoryItemFragment
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category=Lyra)
	TSubclassOf<ULyraEquipmentDefinition> EquipmentDefinition;

	// @D2 Start - 장착아이템을 Widget에 표시하기 위한 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="D2|Equip")
	FName ItemName;
	// @D2 End
};
