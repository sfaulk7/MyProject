// Fill out your copyright notice in the Description page of Project Settings.


#include "SecurityCameraActor.h"

// Sets default values
ASecurityCameraActor::ASecurityCameraActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));// <---
	RootComponent = RootScene;// <---
	
	SecurityCamera = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecurityCamera"));
	DetectionZone = CreateDefaultSubobject<UBoxComponent>(TEXT("DetectionZone"));
	SecurityCameraSpotlight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SecurityCameraSpotlight"));

	SecurityCamera->SetupAttachment(RootComponent);// <---
	DetectionZone->SetupAttachment(RootComponent);// <---
	SecurityCameraSpotlight->SetupAttachment(SecurityCamera);

	DetectionZone->SetCollisionProfileName("OverlapAll");
	DetectionZone->OnComponentBeginOverlap.AddDynamic(this, &ASecurityCameraActor::BeginOverlap);
	

}

// Called when the game starts or when spawned
void ASecurityCameraActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASecurityCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASecurityCameraActor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);

	if (!PlayerCharacter) return;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Spotted!"));
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	AObstacleGamePlayerState* PlayerState = PlayerController != NULL ? PlayerController->GetPlayerState<AObstacleGamePlayerState>() : NULL;
	if (!PlayerState) return;

	PlayerState->UpdatePlayerVisibilityStatus(true);

}

//void ASecurityCameraActor::ChangeSpotlightStatus(bool detecting)
//{
//}

//void ASecurityCameraActor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);
//
//	if (!PlayerCharacter) return;
//
//	if (GEngine)
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Spotted!"));
//	}
//
//	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
//	AObstacleGamePlayerState* PlayerState = PlayerController != NULL ? PlayerController->GetPlayerState<AObstacleGamePlayerState>() : NULL;
//	if (!PlayerState) return;
//
//	PlayerState->UpdatePlayerVisibilityStatus(true);
//
//}

