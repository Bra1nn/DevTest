// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveObjectInterface.h"
#include "GameFramework/Actor.h"
#include "InteractiveObjectBase.generated.h"

UCLASS(Blueprintable)
class OCTOGAMESTEST_API AInteractiveObjectBase : public AActor, public IInteractiveObjectInterface
{
	GENERATED_BODY()

public:
	void HandleCharacterBeginInteraction(AActor* InteractionCouser);
};
