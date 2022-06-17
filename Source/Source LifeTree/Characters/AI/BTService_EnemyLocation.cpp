// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_EnemyLocation.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "../EnemyCharacter.h"
#include "GameFramework/Actor.h"

UBTService_EnemyLocation::UBTService_EnemyLocation()
{
    NodeName = TEXT("Update Enemy Location If Available");
}

void UBTService_EnemyLocation::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) 
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    AActor* Owner = OwnerComp.GetAIOwner();

    TArray<AActor*> EnemyCharacters;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyCharacter::StaticClass(), EnemyCharacters);

    AEnemyCharacter* EnemyCharacter = nullptr;
    for(AActor* Actor : EnemyCharacters)
    {

        EnemyCharacter = Cast<AEnemyCharacter>(Actor);
        if (EnemyCharacter->IsDead() || Owner->GetDistanceTo(EnemyCharacter) > EnemyCharacter->GetDetectionRange())
        {
            EnemyCharacter = nullptr;
        }
        else
        {
            break;
        }
    }

    if (EnemyCharacter == nullptr)
    {
        UE_LOG(LogTemp, Display, TEXT("BTService: No enemies to target"));
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("BTService: Targeting Character Named %s"), *EnemyCharacter->GetHumanReadableName());
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), EnemyCharacter);
    }

}