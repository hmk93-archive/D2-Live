// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenericTeamAgentInterface.h"
#include "D2NpcSpawner.generated.h"

class ULyraPawnData;
class ULyraExperienceDefinition;
class UBehaviorTree;
class AAIController;

UCLASS()
class LYRAGAME_API AD2NpcSpawner : public AActor
{
	GENERATED_BODY()
	
public:	

	AD2NpcSpawner();

protected:

	virtual void BeginPlay() override;

	void OnExperienceLoaded(const ULyraExperienceDefinition* Experience);

	virtual void ServerCreateNPCs();

	APawn* SpawnAIFromClass(UObject* WorldContextObject, ULyraPawnData* LoadedPawnData, UBehaviorTree* BehaviorTreeToRun, FVector Location, FRotator Rotation, bool bNoCollisionFail, AActor* PawnOwner, TSubclassOf<AAIController> ControllerClassToSpawn);

	UFUNCTION()
	void OnSpawnedPawnDestroyed(AActor* DestroyedActor);

	virtual void SpawnOneNPC();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pawn)
	TSoftObjectPtr<ULyraPawnData> PawnData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FGenericTeamId TeamID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	TObjectPtr<UBehaviorTree> BehaviorTree;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn, meta = (UIMin = 1))
	int32 NumNPCToCreate = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	bool ShouldRespawn = false;

	/** Time it takes after pawn death to spawn a new pawn */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn, meta = (EditCondition = ShouldRespawn, EditConditionHides))
	float RespawnTime = 1.f;

	UPROPERTY(EditAnywhere, Category = Gameplay)
	TSubclassOf<AAIController> ControllerClass;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AAIController>> SpawnedNPCList;
};
