#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_GrowMoundLocation.generated.h"

UCLASS()
class LIFETREE_API UBTService_GrowMoundLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTService_GrowMoundLocation();
	
protected:
	virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;

};
