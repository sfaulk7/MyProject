// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ObstacleGamePlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCoinUpdateDispacher, float, NewCoinAmount, float, TotalCoinAmount);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerVisibilityChanged, bool, visibilityStatus);

UCLASS()
class MYPROJECT_API AObstacleGamePlayerState : public APlayerState
{
	GENERATED_BODY()
	
private:
	int Coins = 0;
	//bool visibilityStatus = false;

public:
	int GetCoins();
	bool SetCoins(int amount);

	//bool SetVisibilitystatus(bool newVisibilityStatus);

	UFUNCTION(BlueprintCallable)
	bool AddCoins(int amount);

	UFUNCTION(BlueprintCallable)
	bool UpdatePlayerVisibilityStatus(bool visibilityStatus);

	UPROPERTY(BlueprintAssignable)
	FOnCoinUpdateDispacher OnCoinUpdateDispacher;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerVisibilityChanged OnPlayerVisibilityChanged;
};
