// Fill out your copyright notice in the Description page of Project Settings.


#include "TreeOfLife.h"

void ATreeOfLife::BeginPlay()
{
    Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(FruitTimerHandle, this, &ATreeOfLife::GrowFruit, FirstFruitGrowRate, false);
}

void ATreeOfLife::GrowFruit()
{
	GetWorld()->GetTimerManager().ClearTimer(FruitTimerHandle);
	if (OwnedFruits.Num() < FruitLimit)
	{
		UActorComponent* MeshActorComponent = GetComponentByClass(UStaticMeshComponent::StaticClass());
		USceneComponent* MeshSceneComponent = Cast<USceneComponent>(MeshActorComponent);
		Fruit = GetWorld()->SpawnActor<AFruit>(FruitClass);
		const FAttachmentTransformRules AttachmentTransformRules = FAttachmentTransformRules(
			EAttachmentRule::SnapToTarget, 
			EAttachmentRule::SnapToTarget, 
			EAttachmentRule::KeepWorld, 
			false
		);
		Fruit->AttachToComponent(MeshSceneComponent, AttachmentTransformRules, TEXT("FruitSocket"));
		Fruit->SetOwner(this);
		OwnedFruits.Add(Fruit);
	}
	GetWorld()->GetTimerManager().SetTimer(FruitTimerHandle, this, &ATreeOfLife::DropFruit, FruitGrowRate, false);
}

void ATreeOfLife::DropFruit()
{
	GetWorld()->GetTimerManager().ClearTimer(FruitTimerHandle);
	if (Fruit != nullptr) 
	{
		const FDetachmentTransformRules DetachmentTransformRules = FDetachmentTransformRules(EDetachmentRule::KeepWorld, true);
		Fruit->DetachFromActor(DetachmentTransformRules);
		UActorComponent* ActorComponent = Fruit->GetComponentByClass(UStaticMeshComponent::StaticClass());
		UStaticMeshComponent* StaticMeshComponent = Cast<UStaticMeshComponent>(ActorComponent);
		if (StaticMeshComponent != nullptr) 
		{
			StaticMeshComponent->SetSimulatePhysics(true);
		}
	}
	GetWorld()->GetTimerManager().SetTimer(FruitTimerHandle, this, &ATreeOfLife::GrowFruit, FruitGrowRate, false);
}

void ATreeOfLife::PickFruit(AFruit* PickedFruit)
{
	OwnedFruits.Remove(PickedFruit);
}
