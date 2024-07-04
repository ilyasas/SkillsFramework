// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <FUCK/PlayerCharacter.h>
#include "SkillBase.h"
#include <FUCK/Skills/TestSkill.h>
#include "SkillsComponent.generated.h"





UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FUCK_API USkillsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USkillsComponent();

	//List containing skill classes
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<USkillBase>> skillsClass;

	UPROPERTY()
	TArray <USkillBase*> skillsObject;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SkillOne();
	void SkillTwo();
	void SkillThree();
	void SkillFour();

	//Cast skill by index
	UFUNCTION(BlueprintCallable)
	void Skill(int index);

	//Get skill handler object
	UFUNCTION(BlueprintCallable, BlueprintPure)
	USkillBase* GetSkill(int index);

		
};
