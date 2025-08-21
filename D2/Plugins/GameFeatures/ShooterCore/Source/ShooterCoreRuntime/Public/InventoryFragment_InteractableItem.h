// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Inventory/LyraInventoryItemDefinition.h"
#include "Templates/SubclassOf.h"

#include "InventoryFragment_InteractableItem.generated.h"

class UObject;
class ALyraWorldCollectable;

// @D2 Start - Item Drop 어빌리티에서 사용 
UCLASS()
class UInventoryFragment_InteractableItem : public ULyraInventoryItemFragment
{
	GENERATED_BODY()

public:

	/** Outfit 으로 Spawn 될 Actor 클래스의 메타데이터 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ALyraWorldCollectable> InteractableItem;
};
// @D2 End
