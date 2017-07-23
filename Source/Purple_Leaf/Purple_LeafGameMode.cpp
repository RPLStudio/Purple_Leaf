// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Purple_LeafGameMode.h"
#include "Purple_LeafHUD.h"
#include "Purple_LeafCharacter.h"
#include "UObject/ConstructorHelpers.h"

APurple_LeafGameMode::APurple_LeafGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APurple_LeafHUD::StaticClass();
}
