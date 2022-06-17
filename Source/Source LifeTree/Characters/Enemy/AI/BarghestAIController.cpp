// Fill out your copyright notice in the Description page of Project Settings.


#include "BarghestAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../../../Actors/Items/TreeOfLife.h"

void ABarghestAIController::OnPossess(APawn * InPawn)
{
    Super::OnPossess(InPawn);

    if (AIBehavior == nullptr) return;

    RunBehaviorTree(AIBehavior);
    
    GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), InPawn->GetActorLocation());	

    TArray<AActor*> LifeTrees;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATreeOfLife::StaticClass(), LifeTrees);

    if (sizeof(LifeTrees) > 0)
    {
        GetBlackboardComponent()->SetValueAsObject(TEXT("LifeTree"), LifeTrees[0]);	
    }
}