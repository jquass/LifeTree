#include "BTService_UpdateAreLimbsFull.h"
#include "AIController.h"
#include "../..//LimbedCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_UpdateAreLimbsFull::UBTService_UpdateAreLimbsFull()
{
    NodeName = TEXT("Checks to see if the character's limbs are full.");
}

void UBTService_UpdateAreLimbsFull::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) 
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    if (OwnerComp.GetAIOwner() == nullptr) return;

    ALimbedCharacter* Character = Cast<ALimbedCharacter>(OwnerComp.GetAIOwner()->GetPawn());
    if (Character == nullptr) return;

    if(Character->AreLimbsFull())
    {
        UE_LOG(LogTemp, Display, TEXT("Limbs are FULL ******"));
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true);
    }
    else 
    {
        UE_LOG(LogTemp, Display, TEXT("Limbs are Empty xxxxxx"));
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
}