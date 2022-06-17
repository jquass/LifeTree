// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_FruitLocation.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "../../Actors/Items/Fruit.h"

UBTService_FruitLocation::UBTService_FruitLocation()
{
    NodeName = TEXT("Update Fruit Location If Available");
}

void UBTService_FruitLocation::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) 
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    TArray<AActor*> Fruits;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFruit::StaticClass(), Fruits);
    if (Fruits.Num() == 0)
    {
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
    else
    {
        FVector FruitLocation = Fruits[0]->GetActorLocation();
        UE_LOG(LogTemp, Display, TEXT("Fruits! %s"), *(FruitLocation.ToCompactString()));
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), Fruits[0]);
    }

}