// Fill out your copyright notice in the Description page of Project Settings.


#include "Growable.h"
#include "GrowMound.h"

int AGrowable::Interact(int OccupiedLimbs, int Limbs)
{
	AGrowMound* GrownMound = Cast<AGrowMound>(GetOwner());
	if (GrownMound != nullptr) return GrownMound->Interact(OccupiedLimbs, Limbs);
	
	Destroy();
	return OccupiedLimbs;
}