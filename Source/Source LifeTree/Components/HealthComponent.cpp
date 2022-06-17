// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "../LifeTreeGameModeBase.h"
#include "GameFramework/Character.h" 
#include "Components/CapsuleComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	Health = DefaultHealth;
}

void UHealthComponent::TakeDamage(float DamageAmount)
{
	DamageAmount = FMath::Min(Health, (DamageAmount - Armor));
	Health -= DamageAmount;
	UE_LOG(LogTemp, Display, TEXT("Health Remaining: %f"), Health);

	if (IsDead())
	{
		ALifeTreeGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ALifeTreeGameModeBase>();
		if (GameMode != nullptr)
		{
			GameMode->ActorDestroyed(GetOwner());
		}
 		ACharacter* Character = Cast<ACharacter>(GetOwner());
		if (Character != nullptr)
		{
			UE_LOG(LogTemp, Display, TEXT("DEAD! %s"), *Character->GetHumanReadableName());
			Character->DetachFromControllerPendingDestroy();
			Character->GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
		
	}
}

bool UHealthComponent::IsDead() const
{
	return Health <= 0;
}