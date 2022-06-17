// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LifeTreeGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LIFETREE_API ALifeTreeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDestroyed(AActor* DestroyedActor);
	
};
