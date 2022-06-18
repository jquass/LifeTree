#include "BaseCharacter.h"
#include "../Components/HealthComponent.h"
#include "../Components/LineTraceComponent.h"
#include "GameFramework/Actor.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
	HealthComponent->RegisterComponent();

	LineTraceComponent = CreateDefaultSubobject<ULineTraceComponent>(TEXT("Line Trace"));
	LineTraceComponent->RegisterComponent();
}

void ABaseCharacter::Attack()
{
	if (Attacking) return;

	UE_LOG(LogTemp, Display, TEXT("Starting attack function"));
	FHitResult Hit;
	bool bSuccess = LineTraceComponent->Trace(Hit, this, ECollisionChannel::ECC_GameTraceChannel2);
	if (bSuccess) 
	{
		AActor* Actor = Cast<AActor>(Hit.GetActor());
		if (Actor == nullptr)
		{
			UE_LOG(LogTemp, Display, TEXT("Not an Actor!"));
		 	return;
		}

		UE_LOG(LogTemp, Display, TEXT("Attacked Actor!"));
		Attacking = true;
		Actor->TakeDamage(AttackDamage, FDamageEvent(), Controller, this);
		GetWorld()->GetTimerManager().SetTimer(AttackTimerHandle, this, &ABaseCharacter::StopAttacking, AttackRate, false);
	}
}

float ABaseCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageApplied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	HealthComponent->TakeDamage(DamageApplied);
	return DamageApplied;
}

bool ABaseCharacter::IsDead() const
{
	return HealthComponent->IsDead();
}

bool ABaseCharacter::IsAttacking() const
{
	return Attacking;
}

void ABaseCharacter::StopAttacking()
{
	GetWorld()->GetTimerManager().ClearTimer(AttackTimerHandle);
	Attacking = false;
}