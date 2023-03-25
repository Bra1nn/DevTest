// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayObjects/CinematicDriver.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"

void ACinematicDriver::PlayCinametic(ULevelSequence* LevelSequence)
{
	if (IsValid(LevelSequence))
	{
		UWorld* World = GetWorld();
		if (!IsValid(World))
		{
			UE_LOG(LogTemp, Error, TEXT("UMOT_ACinematicDriver::PlayCinametic: Invalid World, aborting. Check that the task has been initialized properly"));
			return;
		}
		FMovieSceneSequencePlaybackSettings PlaybackSettings;
		PlaybackSettings.bHideHud = true;
		PlaybackSettings.bDisableMovementInput = true;
		PlaybackSettings.bDisableLookAtInput = true;
		PlaybackSettings.bHidePlayer = true;
		ALevelSequenceActor* OutActor = nullptr;
		LevelSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(
			World, LevelSequence, PlaybackSettings, OutActor);
		if (IsValid(LevelSequencePlayer))
		{
			LevelSequencePlayer->OnPlay.AddDynamic(this, &ACinematicDriver::OnCinematicStarted);
			LevelSequencePlayer->OnFinished.AddDynamic(this, &ACinematicDriver::OnCinematicFinished);
			LevelSequencePlayer->Play();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("UMOT_ACinematicDriver::PlayCinametic: Failed to create LevelSequencePlayer"));
		}
	}
}

void ACinematicDriver::OnCinematicFinished_Implementation()
{
}

void ACinematicDriver::OnCinematicStarted_Implementation()
{
}

void ACinematicDriver::BeginPlay()
{
	Super::BeginPlay();
	PlayCinametic(Cinematic);
}
