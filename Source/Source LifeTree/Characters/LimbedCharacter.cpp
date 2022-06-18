#include "LimbedCharacter.h"
#include "../Actors/Item.h"
#include "DrawDebugHelpers.h"
#include "../Components/LineTraceComponent.h"
#include "AIController.h" 
#include "BehaviorTree/BlackboardComponent.h"

void ALimbedCharacter::BeginPlay()
{
	Super::BeginPlay();
	AAIController* AIController = Cast<AAIController>(GetController());
	if (AIController != nullptr)
	{
		AIController->GetBlackboardComponent()->SetValueAsBool(TEXT("True"), true);
	}
}

void ALimbedCharacter::UseItem()
{
	UE_LOG(LogTemp, Display, TEXT("Trying to Use Item"));
	FHitResult Hit;
	bool bSuccess = LineTraceComponent->Trace(Hit, this, ECollisionChannel::ECC_GameTraceChannel1);
	if (bSuccess) {
		UE_LOG(LogTemp, Display, TEXT("Found something"));
		AItem* Item = Cast<AItem>(Hit.GetActor());
		if (Item != nullptr) {
			UE_LOG(LogTemp, Display, TEXT("Found Item"));
			OccupiedLimbs = Item->Interact(OccupiedLimbs, Limbs);
			UE_LOG(LogTemp, Display, TEXT("After using item I have %i OccupiedLimbs of my %i Limbs"), OccupiedLimbs, Limbs);
		}	
		else
		{
			UE_LOG(LogTemp, Display, TEXT("Found a non-Item"));
		}
	}
	AAIController* AIController = Cast<AAIController>(GetController());
	if (AIController != nullptr)
	{
		AIController->GetBlackboardComponent()->SetValueAsBool(TEXT("AreHandsFull"), AreLimbsFull());
	}
}

bool ALimbedCharacter::AreLimbsFull() const
{
	return OccupiedLimbs >= Limbs;
}