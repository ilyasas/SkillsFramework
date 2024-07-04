#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FUCK/PlayerCharacter.h"
#include <Kismet/GameplayStatics.h>
#include "SkillBase.generated.h"

class USkillsComponent;


UCLASS(Blueprintable)
class FUCK_API USkillBase : public UObject
{
	GENERATED_BODY()
	
public:
	USkillBase();

	virtual void Initialize();

	//Skill cooldown in seconds
	UPROPERTY(EditAnywhere)
	float cooldown;

	//Redifine this for Blueprint skill classes
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Cast();

	//Returns cooldown of this handler's skill
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCooldown();

	//Redifine this for C++ skill classes
	virtual void Cast_Implementation();

	//Cut cooldown by set amount (0 to skip cooldown) 
	UFUNCTION(BlueprintCallable)
	void CooldownCut(float cut = 0.f);

	//SkillComponent reference
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly,meta = (EditConditionHides))
	USkillsComponent* skillsComponent;

	//SkillComponent owner reference
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, meta = (EditConditionHides))
	APlayerCharacter* player;

	float cooldownTimestamp;

protected:

private:

};

