// Copyright Zahid Bugra Sarican

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "GameplayTagContainer.h"
#include "AN_SendGameplayEvent.generated.h"

/**
 * 
 */
UCLASS()
class UAN_SendGameplayEvent : public UAnimNotify
{
	GENERATED_BODY()
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override; 	// Zaman noktasında tetiklenen asıl fonksiyon
private:
	UPROPERTY(EditAnywhere, Category = "Gameplay Ability") 	// Gönderilecek Gameplay Event tag’i (Ability.Combo.Change.Combo02 gibi)
	FGameplayTag EventTag;
	virtual FString GetNotifyName_Implementation() const;  	// Editörde notify üstünde görünecek kısa ad (etiketin son parçası)
};