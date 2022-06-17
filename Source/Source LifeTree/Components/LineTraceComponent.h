// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LineTraceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIFETREE_API ULineTraceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULineTraceComponent();

	bool Trace(FHitResult& Hit, ACharacter* Character, ECollisionChannel TraceChannel);

private:
	UPROPERTY(EditAnywhere)
	bool IsDebug;

	UPROPERTY(EditAnywhere)
	float Range = 100;
		
};
