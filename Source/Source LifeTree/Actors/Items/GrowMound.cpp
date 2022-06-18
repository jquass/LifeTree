#include "GrowMound.h"
#include "../../Characters/Limbed/GrowableCharacter.h"

int AGrowMound::Interact(int OccupiedLimbs, int Limbs)
{
	OccupiedLimbs = Super::Interact(OccupiedLimbs, Limbs);

	if (CanPlant && OccupiedLimbs >= 1)
	{
		CanPlant = false;
		GetWorld()->GetTimerManager().SetTimer(GrowTimerHandle, this, &AGrowMound::Grow, GrowRate, false);
		OccupiedLimbs--;
	} 
	else if (CanPick && GrowableCharacterCount < GrowableCharacterLimit && Growable != nullptr) 
	{
		CanPick = false;
		const FVector Location = Growable->GetActorLocation() + FVector::ForwardVector * GrowDistanceForward;
		Growable->Destroy();
		const FRotator Rotation = FTransform(FVector(0)).GetRotation().Rotator();
		FActorSpawnParameters SpawnInfo = FActorSpawnParameters();
		SpawnInfo.Owner = this;
		AGrowableCharacter* GrowableCharacter = GetWorld()->SpawnActor<AGrowableCharacter>(GrowableCharacterClass, Location, Rotation, SpawnInfo);
		GrowableCharacterCount++;	
		CanPlant = true;
	}

	return OccupiedLimbs;
}

bool AGrowMound::GetCanPlant() const
{
	return CanPlant;
}

void AGrowMound::Grow()
{
	GetWorld()->GetTimerManager().ClearTimer(GrowTimerHandle);
	UActorComponent* MeshActorComponent = GetComponentByClass(UStaticMeshComponent::StaticClass());
	USceneComponent* MeshSceneComponent = Cast<USceneComponent>(MeshActorComponent);
	Growable = GetWorld()->SpawnActor<AGrowable>(GrowableClass);
	Growable->AttachToComponent(MeshSceneComponent, FAttachmentTransformRules::KeepRelativeTransform, TEXT("GrowSocket"));
	Growable->SetOwner(this); 
	CanPick = true;
}
