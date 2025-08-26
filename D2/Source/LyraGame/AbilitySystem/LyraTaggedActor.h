// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"

#include "LyraTaggedActor.generated.h"

// An actor that implements the gameplay tag asset interface
UCLASS()
class ALyraTaggedActor : public AActor, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:

	ALyraTaggedActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//~IGameplayTagAssetInterface
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
	//~End of IGameplayTagAssetInterface

	//~UObject interface
#if WITH_EDITOR
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif
	//~End of UObject interface

protected:

	// @D2 Start - B_Hero_Default 에서 Outfits 설정 시 성별 Tag 를 추가할 수 있도록 BlueprintReadOnly 를 BlueprintReadWrite 로 변경
	// Gameplay-related tags associated with this actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Actor)
	FGameplayTagContainer StaticGameplayTags;
	// @D2 End
};

