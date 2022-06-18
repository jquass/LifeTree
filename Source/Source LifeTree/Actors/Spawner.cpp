#include "Spawner.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawner::SpawnBatch, FirstBatchSpawnRate, false);
}

void ASpawner::SpawnBatch()
{
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
	if (BatchesSpawned >= TotalBatches) return;

	BatchesSpawned++;
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawner::Spawn, BatchSpawnRate, false);
}

void ASpawner::Spawn()
{
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
	if (SpawnedInBatch >= BatchSize)
	{
		SpawnedInBatch = 0;
		GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawner::SpawnBatch, SpawnRate, false);
		return;
	}
	float SpawnRadiusX = GetSpawnRadius();
	float SpawnRadiusY = GetSpawnRadius();
	const FVector Location = GetActorLocation() + FVector::ForwardVector * SpawnRadiusX + FVector(0,1,0) * SpawnRadiusY;		
	const FRotator Rotation = FTransform(FVector(0)).GetRotation().Rotator();
	FActorSpawnParameters SpawnInfo = FActorSpawnParameters();
	SpawnInfo.Owner = this;
	AActor* Actor = GetWorld()->SpawnActor<AActor>(ActorClass, Location, Rotation, SpawnInfo);
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawner::Spawn, SpawnRate, false);
	SpawnedInBatch++;
}

float ASpawner::GetSpawnRadius()
{
	return FMath::RandRange(-SpawnRadius, SpawnRadius);
}
