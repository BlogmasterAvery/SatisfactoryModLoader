#include "GWM_UnlimitedLifts.h"

#include "UnlimitedLifts/UnlimitedLiftsModule.h"



void UGWM_UnlimitedLifts::DispatchLifecycleEvent(ELifecyclePhase Phase)
{
	Super::DispatchLifecycleEvent(Phase);

	UE_LOG(LogUnlimitedLifts, Verbose, TEXT("GIM_UnlimitedLifts::DispatchLifecycleEvent - %s"), *StaticEnum<ELifecyclePhase>()->GetValueAsString(Phase));
}