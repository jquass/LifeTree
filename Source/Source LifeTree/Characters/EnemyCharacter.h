// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class LIFETREE_API AEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	float GetDetectionRange();

private:
	UPROPERTY(EditDefaultsOnly)
	float DetectionRange = 2000;

};
