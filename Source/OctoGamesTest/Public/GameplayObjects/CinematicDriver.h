// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelSequencePlayer.h"
#include "CinematicDriver.generated.h"

UCLASS()
class OCTOGAMESTEST_API ACinematicDriver : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	ULevelSequence* Cinematic;
	UPROPERTY()
	ULevelSequencePlayer* LevelSequencePlayer;
	void PlayCinametic(ULevelSequence* LevelSequence);
	UFUNCTION(BlueprintNativeEvent)
	void OnCinematicFinished();
	UFUNCTION(BlueprintNativeEvent)
	void OnCinematicStarted();

protected:
	virtual void BeginPlay() override;
};
