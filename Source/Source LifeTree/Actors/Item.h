// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Components/HealthComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class LIFETREE_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure)
	bool IsDestroyed() const;

	virtual int Interact(int OccupiedLimbs, int Limbs);

private:
	UPROPERTY(VisibleAnywhere)
	UHealthComponent* HealthComponent;

};
