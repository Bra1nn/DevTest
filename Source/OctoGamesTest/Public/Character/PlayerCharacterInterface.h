// Copyright 2022 Dragon Machines LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerCharacterInterface.generated.h"

UINTERFACE()
class UPlayerCharacterInterface : public UInterface
{
	GENERATED_BODY()
};

class OCTOGAMESTEST_API IPlayerCharacterInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void PlayInteractiveMontage(UAnimMontage* Animation, bool CanBeAborted);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void PickUpItem(UClass* Item);
};
