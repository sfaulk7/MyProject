// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/SpotLightComponent.h"
#include "ObstacleGamePlayerState.h"


#include "SecurityCameraActor.generated.h"

UCLASS()
class MYPROJECT_API ASecurityCameraActor : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASecurityCameraActor();
	
	UPROPERTY(BlueprintReadWrite)
	USceneComponent* RootScene;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBoxComponent* DetectionZone;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* SecurityCamera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USpotLightComponent* SecurityCameraSpotlight;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UFUNCTION()
	//void ChangeSpotlightStatus(bool detecting);

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

};
