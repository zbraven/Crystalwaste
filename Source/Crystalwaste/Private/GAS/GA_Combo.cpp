// Copyright Zahid Bugra Sarican


#include "GAS/GA_Combo.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "GAS/CAbilitySystemStatics.h"

UGA_Combo::UGA_Combo()
{
	AbilityTags.AddTag(UCAbilitySystemStatics::GetBasicAttackAbilityTag());
	BlockAbilitiesWithTag.AddTag(UCAbilitySystemStatics::GetBasicAttackAbilityTag());
}

void UGA_Combo::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                const FGameplayAbilityActivationInfo ActivationInfo,
                                const FGameplayEventData* TriggerEventData)
{
	// Mana veya cooldown kontrolü
	if (!K2_CommitAbility())
	{
		K2_EndAbility();
		return;
	}
	
	// Yalnızca server veya local predictive client oynatsın
	if (HasAuthorityOrPredictionKey(ActorInfo, &ActivationInfo))
	{
		// AbilityTask olustur (Play Montage)
		UAbilityTask_PlayMontageAndWait* PlayComboMontageTask =
			UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this, NAME_None, ComboMontage);
		//Her durumda combomuzu sonlandiriyorum
		PlayComboMontageTask->OnBlendOut.AddDynamic(this, &UGA_Combo::K2_EndAbility);
		PlayComboMontageTask->OnCancelled.AddDynamic(this, &UGA_Combo::K2_EndAbility);
		PlayComboMontageTask->OnCompleted.AddDynamic(this, &UGA_Combo::K2_EndAbility);
		PlayComboMontageTask->OnInterrupted.AddDynamic(this, &UGA_Combo::K2_EndAbility);
		PlayComboMontageTask->ReadyForActivation();
	}
}
