#include "BTTask_EnemyAttack.h"
#include "AIController.h"
#include "../../EnemyCharacter.h"

UBTTask_EnemyAttack::UBTTask_EnemyAttack()
{
    NodeName = TEXT("Attack from an Enemy");
}

EBTNodeResult::Type UBTTask_EnemyAttack::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    UE_LOG(LogTemp, Display, TEXT("Starting to attack"));
    if (OwnerComp.GetAIOwner() == nullptr) 
    {
        UE_LOG(LogTemp, Display, TEXT("No AI Owner"));
        return EBTNodeResult::Failed;
    }

    AEnemyCharacter* Character = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
    if (Character == nullptr) 
    {
        UE_LOG(LogTemp, Display, TEXT("Failed casting character"));
        return EBTNodeResult::Failed;
    }

    Character->Attack();
    return EBTNodeResult::Succeeded;
}