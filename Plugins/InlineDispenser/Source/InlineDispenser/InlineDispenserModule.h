#pragma once

#include "Modules/ModuleManager.h"

#include "FGFactoryConnectionComponent.h"

DECLARE_LOG_CATEGORY_EXTERN(LogInlineDispenser, Log, All);


class FInlineDispenserModule : public FDefaultGameModuleImpl {
public:
	virtual void StartupModule() override;

	virtual bool IsGameModule() const override { return true; }

private:

};