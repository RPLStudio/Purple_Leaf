// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Purple_LeafHUD.generated.h"

UCLASS()
class APurple_LeafHUD : public AHUD
{
	GENERATED_BODY()

public:
	APurple_LeafHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

