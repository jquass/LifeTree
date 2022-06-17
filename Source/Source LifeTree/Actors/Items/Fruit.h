// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Item.h"
#include "Fruit.generated.h"

/**
 * 
 */
UCLASS()
class LIFETREE_API AFruit : public AItem
{
	GENERATED_BODY()
	
public:
	AFruit();

	int Interact(int OccupiedLimbs, int Limbs) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

};
