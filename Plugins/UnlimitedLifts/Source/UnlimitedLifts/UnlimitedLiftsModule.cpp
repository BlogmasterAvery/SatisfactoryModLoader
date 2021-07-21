#include "UnlimitedLiftsModule.h"

#include "Kismet/KismetMathLibrary.h"
#include "Patching/NativeHookManager.h"

DEFINE_LOG_CATEGORY(LogUnlimitedLifts);

void FUnlimitedLiftsModule::StartupModule()
{
#if !WITH_EDITOR
	SUBSCRIBE_METHOD_VIRTUAL_AFTER(AFGConveyorLiftHologram::BeginPlay, GetMutableDefault<AFGConveyorLiftHologram>(), [this](AFGConveyorLiftHologram* FGConveyorLiftHologram)
	{
		hookFGConveyorLiftHologram(FGConveyorLiftHologram);
	});

	//SUBSCRIBE_METHOD(AFGConveyorLiftHologram::CanConnectToConnection, [this](auto& Scope, const AFGConveyorLiftHologram* self, UFGFactoryConnectionComponent* from, UFGFactoryConnectionComponent* to)
	//{
	//	Scope.Override(Scope(self, from, to) || hookCanConnectToConnection(self, from, to));
	//});
#endif
}

void FUnlimitedLiftsModule::hookFGConveyorLiftHologram(AFGConveyorLiftHologram* FGConveyorLiftHologram)
{
	resolveGWM();//if (!IsValid(GWM)) resolveGWM();

	//UE_LOG(LogUnlimitedLifts, Warning, TEXT("Conveyor lift min and max height are %f, %f"), FGConveyorLiftHologram->mMinimumHeight, FGConveyorLiftHologram->mMaximumHeight);

	FGConveyorLiftHologram->mMaximumHeight = FMath::Max(FGConveyorLiftHologram->mMinimumHeight, GWM->configConveyorLiftMaxHeight);

	//UE_LOG(LogUnlimitedLifts, Warning, TEXT("Conveyor lift max height is now %f"), FGConveyorLiftHologram->mMaximumHeight);
}

//bool FUnlimitedLiftsModule::hookCanConnectToConnection(const AFGConveyorLiftHologram* FGConveyorLiftHologram, UFGFactoryConnectionComponent* from, UFGFactoryConnectionComponent* to) const
//{
//	return true;
//}

void FUnlimitedLiftsModule::resolveGWM()
{
	TArray<UObject*> Objs;
	GetObjectsOfClass(UGWM_UnlimitedLifts::StaticClass(), Objs);
	GWM = Cast<UGWM_UnlimitedLifts>(Objs[0]);
	if (!IsValid(GWM)) UE_LOG(LogUnlimitedLifts, Fatal, TEXT("Failed to find Game World Module!"));
}

IMPLEMENT_GAME_MODULE(FUnlimitedLiftsModule, UnlimitedLifts);