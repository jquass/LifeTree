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
    AActor* LifeTree;
    UGameplayStatics::GetActorOfClass(GetWorld(), ATreeOfLife::StaticClass(), LifeTree);
    GetBlackboardComponent()->SetValueAsObject(TEXT("LifeTree"), LifeTree);	
}