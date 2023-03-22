// Copyright Epic Games, Inc. All Rights Reserved.

#include "OctoGamesTestGameMode.h"
#include "OctoGamesTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOctoGamesTestGameMode::AOctoGamesTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
