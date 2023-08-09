#pragma once

#include "CoreMinimal.h"
#include "FGFactoryConnectionComponent.h"
#include "Buildables\FGBuildableConveyorBase.h"
#include "Buildables\FGBuildableAttachmentMerger.h"
#include "InlineBuffer.generated.h"

UCLASS()
class INLINEDISPENSER_API AInlineBuffer : public AFGBuildableAttachmentMerger
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void MakeConnection(class UFGFactoryConnectionComponent* fromComponent, class UFGFactoryConnectionComponent* toComponent);
	UFUNCTION(BlueprintCallable)
	float GetConveyorLength(class AFGBuildableConveyorBase* belt);
	UFUNCTION(BlueprintCallable)
	void SetConveyorLength(class AFGBuildableConveyorBase* belt, float newLength);
};