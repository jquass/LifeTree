// Fill out your copyright notice in the Description page of Project Settings.


#include "Fruit.h"
#include "TreeOfLife.h"

AFruit::AFruit()
{ 
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
}

int AFruit::Interact(int OccupiedLimbs, int Limbs)
{
    OccupiedLimbs = Super::Interact(OccupiedLimbs, Limbs);

	UE_LOG(LogTemp, Display, TEXT("Fruit is being used, %i %i"), OccupiedLimbs, Limbs);

	if (OccupiedLimbs >= Limbs) return OccupiedLimbs;

    ATreeOfLife* TreeOfLife = Cast<ATreeOfLife>(GetOwner());
	if (TreeOfLife != nullptr)
	{
		TreeOfLife->PickFruit(this);
	}
	Destroy();
	int NewOccupiedLimbs = OccupiedLimbs + 1;
	UE_LOG(LogTemp, Display, TEXT("Now I have %i OccupiedLimbs"), NewOccupiedLimbs);
	return NewOccupiedLimbs;
}