#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BarghestAIController.generated.h"

/**
 * 
 */
UCLASS()
class LIFETREE_API ABarghestAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void OnPossess(APawn * InPawn) override;

private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;

};
