// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../Characters/Limbed/GrowableCharacter.h"
#include "Growable.h"
#include "../Item.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrowMound.generated.h"

UCLASS()
class LIFETREE_API AGrowMound : public AItem
{
	GENERATED_BODY()
	
public:	
	virtual int Interact(int OccupiedLimbs, int Limbs) override;

	bool GetCanPlant() const;

private:
	UPROPERTY(VisibleAnywhere)
	bool CanPlant = true;

	UPROPERTY(VisibleAnywhere)
	bool CanPick = false;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGrowable> GrowableClass;

	UPROPERTY()
	AGrowable* Growable;

	UPROPERTY(EditAnywhere)
	float GrowRate = 60.0;

	UFUNCTION()
	void Grow();

	FTimerHandle GrowTimerHandle;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGrowableCharacter> GrowableCharacterClass;

	UPROPERTY(VisibleAnywhere)
	int GrowableCharacterCount = 0;

	UPROPERTY(EditAnywhere)
	int GrowableCharacterLimit = 1;

	UPROPERTY(EditAnywhere)
	int GrowDistanceForward = 200;

};
