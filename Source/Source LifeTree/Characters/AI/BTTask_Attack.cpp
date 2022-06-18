#include "BTTask_Attack.h"
#include "AIController.h"
#include "../BaseCharacter.h"

UBTTask_Attack::UBTTask_Attack()
{
    NodeName = TEXT("Base Character Attack");
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    UE_LOG(LogTemp, Display, TEXT("Starting to attack"));
    if (OwnerComp.GetAIOwner() == nullptr) 
    {
        UE_LOG(LogTemp, Display, TEXT("No AI Owner"));
        return EBTNodeResult::Failed;
    }

    ABaseCharacter* Character = Cast<ABaseCharacter>(OwnerComp.GetAIOwner()->GetPawn());
    if (Character == nullptr) 
    {
        UE_LOG(LogTemp, Display, TEXT("Failed casting character"));
        return EBTNodeResult::Failed;
    }

    Character->Attack();
    return EBTNodeResult::Succeeded;
}