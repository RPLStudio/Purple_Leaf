// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Lib.h"
#include "Saving.h"
#include "PurpleLeafCharacter.generated.h"

UCLASS(config=Game)
class APurpleLeafCharacter : public ACharacter
{
	GENERATED_BODY()


	

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	APurpleLeafCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();
	
	

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	USkeletalMeshComponent* PlayerMesh;
	//variables
	//体力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		int Fatigue = 500;

	//跑步状态
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		bool IsRunning = false;

	//跑步开始
	UFUNCTION(BlueprintCallable)
		void Run();

	//跑步结束
	UFUNCTION(BlueprintCallable)
		void StopRun();

	//拾取状态
	bool IsPickingUp = false;

	//物品栏
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		TArray<int> inventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		TArray<FString> log;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		bool FirstPersonMode = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		USaving *SaveData;
	//functions

	void Tick(float dt) override;

	//开始拾取
	UFUNCTION()
	void StartPickingUp();

	UFUNCTION()
	void EndPickingUp();


	UFUNCTION(BlueprintCallable)
		static int GetItemInInventory(int index);

	UFUNCTION(BlueprintCallable)
		static int SetItemInInventory(int index);

	UFUNCTION(BlueprintCallable)
		void SwitchView();



};

