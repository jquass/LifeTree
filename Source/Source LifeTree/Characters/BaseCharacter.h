#pragma once

#include "../Components/HealthComponent.h"
#include "../Components/LineTraceComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class LIFETREE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	void Attack();

	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintPure)
	bool IsAttacking() const;

	UFUNCTION()
	void StopAttacking();

	UPROPERTY(VisibleAnywhere)
	ULineTraceComponent* LineTraceComponent;

private:
	UPROPERTY(VisibleAnywhere)
	UHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly)
	float AttackDamage = 5;

	UPROPERTY()
	bool Attacking;

	UPROPERTY()
	FTimerHandle AttackTimerHandle;

	UPROPERTY(EditDefaultsOnly)
	float AttackRate = 1.0;
};
