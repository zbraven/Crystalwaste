// Copyright Zahid Bugra Sarican


#include "GAS/CAbilitySystemComponent.h"

void UCAbilitySystemComponent::ApplyInitialEffects()
{
	for (const TSubclassOf<UGameplayEffect>& EffectClass : InitialEffects)
	{
		FGameplayEffectSpecHandle EffectSpecHandle = MakeOutgoingSpec(EffectClass, 1, MakeEffectContext());
		ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	}
}
