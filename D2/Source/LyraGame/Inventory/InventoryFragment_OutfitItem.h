// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Inventory/LyraInventoryItemDefinition.h"

#include "InventoryFragment_OutfitItem.generated.h"

class UObject;
class USkeletalMesh;

// @D2 Start - 옷 장비와 관련된 아이템 변경여부를 담당하는 Fragment
UCLASS()
class UInventoryFragment_OutfitItem : public ULyraInventoryItemFragment
{
	GENERATED_BODY()

public:

	/** Skeletal Mesh Component 에 설정 될 에셋 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Outfits)
	TObjectPtr<USkeletalMesh> SkeletalMeshAsset;
};
// @D2 End
