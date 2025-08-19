// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Inventory/LyraInventoryItemDefinition.h"

#include "InventoryFragment_OutfitItem.generated.h"

class UObject;
class AActor;

// @D2 Start - 옷 장비와 관련된 아이템 변경여부를 담당하는 Fragment
UCLASS()
class UInventoryFragment_OutfitItem : public ULyraInventoryItemFragment
{
	GENERATED_BODY()

public:

	/** Outfit 으로 Spawn 될 Actor 클래스의 메타데이터 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Outfits)
	TSubclassOf<AActor> OutfitClass;
};
// @D2 End
