#include "InlineBuffer.h"

#include "InlineDispenser/InlineDispenserModule.h"

void AInlineBuffer::MakeConnection(class UFGFactoryConnectionComponent* fromComponent, class UFGFactoryConnectionComponent* toComponent)
{
	fromComponent->SetConnection(toComponent);
}

float AInlineBuffer::GetConveyorLength(class AFGBuildableConveyorBase* belt)
{
	return belt->mLength;
}

void AInlineBuffer::SetConveyorLength(class AFGBuildableConveyorBase* belt, float newLength)
{
	belt->mLength = newLength;
}