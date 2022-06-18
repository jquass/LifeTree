#include "BTService_GrowMoundLocation.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "../../Actors/Items/GrowMound.h"

UBTService_GrowMoundLocation::UBTService_GrowMoundLocation()
{
    NodeName = TEXT("Update Grow Mound");
}

void UBTService_GrowMoundLocation::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) 
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    TArray<AActor*> GrowMounds;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGrowMound::StaticClass(), GrowMounds);
    AGrowMound* GrowMound = nullptr;
    for(AActor* Actor : GrowMounds)
    {
        GrowMound = Cast<AGrowMound>(Actor);
        if (!GrowMound->GetCanPlant())
        {
            GrowMound = nullptr;
        }
        else
        {
            break;
        }
    }
    if (GrowMound == nullptr)
    {
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), GrowMound);
    }
}
