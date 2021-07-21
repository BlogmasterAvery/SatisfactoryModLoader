#pragma once

#include "Modules/ModuleManager.h"

#include "FGFactoryConnectionComponent.h"
#include "Hologram/FGConveyorLiftHologram.h"
#include "GWM_UnlimitedLifts.h"

DECLARE_LOG_CATEGORY_EXTERN(LogUnlimitedLifts, Log, All);


class FUnlimitedLiftsModule : public FDefaultGameModuleImpl {
public:
	virtual void StartupModule() override;

	virtual bool IsGameModule() const override { return true; }

	void hookFGConveyorLiftHologram(AFGConveyorLiftHologram* FGConveyorLiftHologram);

	//bool hookCanConnectToConnection(const AFGConveyorLiftHologram* FGConveyorLiftHologram, UFGFactoryConnectionComponent* Connection0, UFGFactoryConnectionComponent* Connection1) const;

	UGWM_UnlimitedLifts* GWM;

private:
	void  resolveGWM();
};