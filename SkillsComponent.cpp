#include "SkillsComponent.h"

// Sets default values for this component's properties
USkillsComponent::USkillsComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void USkillsComponent::BeginPlay()
{
	Super::BeginPlay();
	
	for (int32 i = 0; i < skillsClass.Num(); i++)
	{
		if (skillsClass[i])
		{
			skillsObject.Add(NewObject<USkillBase>(this->GetOwner(), skillsClass[i]));
		}

		if (skillsObject[i])
		{
			skillsObject[i]->cooldownTimestamp = 1.f;
			skillsObject[i]->skillsComponent = this;
			skillsObject[i]->player = GetOwner();
		}
	}
}

void USkillsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void USkillsComponent::Skill(int index)
{
	if (skillsObject.IsValidIndex(index))
		if (skillsObject[index])
		{
			skillsObject[index]->Initialize();
		}
}

USkillBase* USkillsComponent::GetSkill(int index)
{
	return skillsObject[index];
}
