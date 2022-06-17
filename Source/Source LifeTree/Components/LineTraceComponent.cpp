// Fill out your copyright notice in the Description page of Project Settings.


#include "LineTraceComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
ULineTraceComponent::ULineTraceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool ULineTraceComponent::Trace(FHitResult& Hit, ACharacter* Character, ECollisionChannel TraceChannel)
{
	if (Character->GetController() == nullptr) return false;

	FVector Location;
	FRotator Rotation;
	Character->GetController()->GetPlayerViewPoint(Location, Rotation);
	FVector End = Location + Rotation.Vector() * Range;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(Character);
	Params.AddIgnoredActor(Character->GetOwner());
	if (IsDebug)
	{
		DrawDebugLine(GetWorld(), Location, End, FColor::Red, true, -1, 0, 5);
		DrawDebugCamera(GetWorld(), Location, Rotation, 90, 3, FColor::Red, true);
	}
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, TraceChannel, Params);
}

