// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_UpdateAreLimbsFull.generated.h"

/**
 * 
 */
UCLASS()
class LIFETREE_API UBTService_UpdateAreLimbsFull : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:

	UBTService_UpdateAreLimbsFull();
	
protected:

	virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;

};
