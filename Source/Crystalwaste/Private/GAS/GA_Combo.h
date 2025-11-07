// Copyright Zahid Bugra Sarican

#pragma once

#include "CoreMinimal.h"
#include "GAS/CGameplayAbility.h"
#include "GA_Combo.generated.h"

/**
 * 
 */
UCLASS()
class UGA_Combo : public UCGameplayAbility
{
	GENERATED_BODY()
	
public:
	UGA_Combo();
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
private:
	// Blueprint’ten atayabileceğimiz animasyon montajı
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* ComboMontage;
};
