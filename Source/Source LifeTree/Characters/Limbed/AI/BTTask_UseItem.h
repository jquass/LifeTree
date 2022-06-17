// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_UseItem.generated.h"

/**
 * 
 */
UCLASS()
class LIFETREE_API UBTTask_UseItem : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_UseItem();
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
	
};
