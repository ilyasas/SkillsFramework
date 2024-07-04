#include "SkillBase.h"


USkillBase::USkillBase()
{
	cooldownTimestamp = 0.f;
	cooldown = 0.f;
}

void USkillBase::Initialize()
{
	if (UGameplayStatics::GetTimeSeconds(GetWorld()) >= cooldownTimestamp)
	{			
		cooldownTimestamp = UGameplayStatics::GetTimeSeconds(GetWorld()) + cooldown;
		Cast();
	}
}

void USkillBase::Cast_Implementation()
{
	
}

void USkillBase::CooldownCut(float cut)
{
	if (cut != 0.f)
	{
		cooldownTimestamp += -cut;
	}
	else
	{
		cooldownTimestamp = 0.0f;
	}
}

float USkillBase::GetCooldown()
{
	return  FMath::Clamp(cooldownTimestamp - UGameplayStatics::GetTimeSeconds(GetWorld()), 0, INFINITY);
}
