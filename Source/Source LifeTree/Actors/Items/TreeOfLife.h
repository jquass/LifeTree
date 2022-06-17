// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fruit.h"
#include "CoreMinimal.h"
#include "../Item.h"
#include "TreeOfLife.generated.h"

/**
 * 
 */
UCLASS()
class LIFETREE_API ATreeOfLife : public AItem
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:

	void PickFruit(AFruit* Fruit);
	
private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFruit> FruitClass;

	UPROPERTY(EditAnywhere)
	int FruitLimit = 10;

	UPROPERTY() 
	AFruit* Fruit;

	UPROPERTY()
	TArray<AFruit*> OwnedFruits;

	UPROPERTY(EditAnywhere)
	float FruitGrowRate = 30.0;

	UPROPERTY(EditAnywhere)
	float FirstFruitGrowRate = 1.0;

	UFUNCTION()
	void GrowFruit();

	UFUNCTION()
	void DropFruit();

	UPROPERTY()
	FTimerHandle FruitTimerHandle;

};
