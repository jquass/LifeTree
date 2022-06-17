// Fill out your copyright notice in the Description page of Project Settings.

#include "FoxAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../GrowableCharacter.h"

void AFoxAIController::OnPossess(APawn * InPawn)
{
    Super::OnPossess(InPawn);

    if (AIBehavior == nullptr) return;

    RunBehaviorTree(AIBehavior);
    
    GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), InPawn->GetActorLocation());	
}