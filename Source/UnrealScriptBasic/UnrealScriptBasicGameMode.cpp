// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealScriptBasicGameMode.h"
#include "UnrealScriptBasicCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealScriptBasicGameMode::AUnrealScriptBasicGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
