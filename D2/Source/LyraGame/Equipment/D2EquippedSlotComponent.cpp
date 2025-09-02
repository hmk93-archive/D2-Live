// Copyright Epic Games, Inc. All Rights Reserved.

#include "D2EquippedSlotComponent.h"

#include "Equipment/LyraEquipmentDefinition.h"
#include "Equipment/LyraEquipmentInstance.h"
#include "Equipment/LyraEquipmentManagerComponent.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "GameFramework/Pawn.h"
#include "Inventory/InventoryFragment_EquippableItem.h"
#include "NativeGameplayTags.h"
#include "Net/UnrealNetwork.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(D2EquippedSlotComponent)

UD2EquippedSlotComponent::UD2EquippedSlotComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetIsReplicatedByDefault(true);
}

void UD2EquippedSlotComponent::BeginPlay()
{
	Slots.AddDefaulted(int32(ED2EquippedSlotKey::Count));
}

void UD2EquippedSlotComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, Slots);
}

void UD2EquippedSlotComponent::OnRep_Slots()
{
}

void UD2EquippedSlotComponent::AddItemToSlot(FGameplayTag Tag, ULyraInventoryItemInstance* Item)
{
	int32 SlotIndex = FindKeyFromTag(Tag);
	if ((SlotIndex != -1) && (Item != nullptr))
	{
		Slots[SlotIndex] = Item;
		OnRep_Slots();
	}
}

int32 UD2EquippedSlotComponent::FindKeyFromTag(FGameplayTag Tag)
{
	FGameplayTag CompTag = FGameplayTag::RequestGameplayTag(FName("Outfits.Male.NormalWeight.Torso"));

	if (CompTag.MatchesTagExact(Tag))
	{
		return int32(ED2EquippedSlotKey::Torso);
	}

	CompTag = FGameplayTag::RequestGameplayTag(FName("Outfits.Male.NormalWeight.Legs"));
	if (CompTag.MatchesTagExact(Tag))
	{
		return int32(ED2EquippedSlotKey::Legs);
	}

	CompTag = FGameplayTag::RequestGameplayTag(FName("Outfits.Male.NormalWeight.Shoes"));
	if (CompTag.MatchesTagExact(Tag))
	{
		return int32(ED2EquippedSlotKey::Shoes);
	}

	return -1;
}
