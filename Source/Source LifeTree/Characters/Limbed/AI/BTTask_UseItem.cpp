#include "BTTask_UseItem.h"
#include "AIController.h"
#include "../../LimbedCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_UseItem::UBTTask_UseItem()
{
	NodeName = TEXT("Use an Item");
}

EBTNodeResult::Type UBTTask_UseItem::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr) 
    {
        return EBTNodeResult::Failed;
    }

    ALimbedCharacter* Character = Cast<ALimbedCharacter>(OwnerComp.GetAIOwner()->GetPawn());
    if (Character == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    Character->UseItem();
    return EBTNodeResult::Succeeded;
}