// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = false;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
	HealthComponent->RegisterComponent();
}

float AItem::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageApplied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	HealthComponent->TakeDamage(DamageApplied);
	return DamageApplied;
}

bool AItem::IsDestroyed() const
{
	return HealthComponent->IsDead();
}

int AItem::Interact(int OccupiedLimbs, int Limbs)
{
	return OccupiedLimbs;
}