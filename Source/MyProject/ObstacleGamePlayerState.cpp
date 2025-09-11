// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleGamePlayerState.h"

int AObstacleGamePlayerState::GetCoins()
{
	return Coins;
}

bool AObstacleGamePlayerState::SetCoins(int amount)
{
	Coins = amount;
	return true;
}

bool AObstacleGamePlayerState::AddCoins(int amount)
{
	int coins = GetCoins();
	int newCoinAmount = coins + amount;
	SetCoins(newCoinAmount);
	OnCoinUpdateDispacher.Broadcast(amount, newCoinAmount);
	return true;
}

bool AObstacleGamePlayerState::UpdatePlayerVisibilityStatus(bool visibilityStatus)
{
	OnPlayerVisibilityChanged.Broadcast(visibilityStatus);
	return true;
}

//bool AObstacleGamePlayerState::UpdatePlayerVisibilityStatus(bool newVisibilityStatus)
//{
//	
//}
