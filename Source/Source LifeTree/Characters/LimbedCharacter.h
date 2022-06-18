#pragma once

#include "BaseCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LimbedCharacter.generated.h"

UCLASS()
class LIFETREE_API ALimbedCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:	
	void UseItem();

	UFUNCTION(BlueprintPure)
	bool AreLimbsFull() const;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	float LimbLength = 100;

	UPROPERTY(VisibleAnywhere)
	unsigned int OccupiedLimbs = 0;

	UPROPERTY(EditAnywhere)
	unsigned int Limbs = 2;

};
