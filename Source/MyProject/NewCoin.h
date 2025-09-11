// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewCoin.generated.h"

UCLASS()
class MYPROJECT_API ANewCoin : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANewCoin();

	UPROPERTY(BlueprintReadWrite)
	USceneComponent* RootScene;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* Coin;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};
