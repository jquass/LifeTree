#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIFETREE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

	void TakeDamage(float DamageAmount);

	UFUNCTION(BlueprintPure)
	bool IsDead() const;

private:
	UPROPERTY(EditDefaultsOnly)
	float DefaultHealth = 100;

	UPROPERTY()
	float Health;

	UPROPERTY(EditDefaultsOnly)
	float Armor = 0;
};
