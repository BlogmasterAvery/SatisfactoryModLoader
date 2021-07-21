#pragma once

#include "CoreMinimal.h"
#include "Module/GameWorldModule.h"
#include "Hologram/FGConveyorLiftHologram.h"
#include "GWM_UnlimitedLifts.generated.h"

UCLASS()
class UNLIMITEDLIFTS_API UGWM_UnlimitedLifts : public UGameWorldModule
{
	GENERATED_BODY()
public:
	virtual void DispatchLifecycleEvent(ELifecyclePhase Phase) override;

	UPROPERTY(BlueprintReadWrite)
	float configConveyorLiftMaxHeight;
};