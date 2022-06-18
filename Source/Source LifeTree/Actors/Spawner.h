#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class LIFETREE_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawner();

protected:
	virtual void BeginPlay() override;

private:

	void Spawn();

	void SpawnBatch();

	UPROPERTY(EditDefaultsOnly)
	float SpawnRadius = 500;
	
	float GetSpawnRadius();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> ActorClass;

	UPROPERTY()
	FTimerHandle SpawnTimerHandle;

	UPROPERTY(EditDefaultsOnly)
	float SpawnRate = 1.0;

	UPROPERTY(EditDefaultsOnly)
	float FirstBatchSpawnRate = 90.0;

	UPROPERTY(EditDefaultsOnly)
	float BatchSpawnRate = 60.0;

	UPROPERTY(EditDefaultsOnly)
	int BatchSize = 3;

	UPROPERTY(VisibleAnywhere)
	int SpawnedInBatch = 0;

	UPROPERTY(EditDefaultsOnly)
	int TotalBatches = 20;

	UPROPERTY(VisibleAnywhere)
	int BatchesSpawned = 0;

};
