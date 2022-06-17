// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Item.h"
#include "Growable.generated.h"

/**
 * 
 */
UCLASS()
class LIFETREE_API AGrowable : public AItem
{
	GENERATED_BODY()
	
public:
	virtual int Interact(int OccupiedLimbs, int Limbs) override;
};
