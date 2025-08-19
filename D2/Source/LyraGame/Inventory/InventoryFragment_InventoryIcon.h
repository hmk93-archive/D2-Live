// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Inventory/LyraInventoryItemDefinition.h"
#include "Styling/SlateBrush.h"

#include "InventoryFragment_InventoryIcon.generated.h"

class UObject;

// @D2 Start - Inventory Tile UI Image 표기를 위한 Fragment
UCLASS()
class UInventoryFragment_InventoryIcon : public ULyraInventoryItemFragment
{
	GENERATED_BODY()

public:

	/** InventoryFragment_QuickBarIcon 를 참고 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Appearance)
	FSlateBrush Brush;
};
// @D2 End
