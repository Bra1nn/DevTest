// Copyright 2022 Dragon Machines LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractiveObjectInterface.generated.h"

UINTERFACE()
class UInteractiveObjectInterface : public UInterface
{
	GENERATED_BODY()
};

class OCTOGAMESTEST_API IInteractiveObjectInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool Interact(AActor* Instigator);
};
