// Fill out your copyright notice in the Description page of Project Settings.


#include "NewCoin.h"
#include "GameFramework/Character.h"
#include "ObstacleGamePlayerState.h"

// Sets default values
ANewCoin::ANewCoin()

{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));// <---
	RootComponent = RootScene;// <---

	Coin = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin"));

	Coin->SetupAttachment(RootComponent);// <---

	Coin->OnComponentBeginOverlap.AddDynamic(this, &ANewCoin::BeginOverlap);

}

// Called when the game starts or when spawned

void ANewCoin::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame

void ANewCoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//void ANewCoin::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	//ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);
//	if (GEngine) {
//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
//	}
//	//if (!PlayerCharacter) return;
//
//	//APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
//
//	//AOCPlayerState* PlayerState = PlayerController != NULL ? PlayerController->GetPlayerState<AOCPlayerState>() : NULL;
//	//if (!PlayerState) return;
//
//	//PlayerState->AddCoins(Coins);
//	Destroy();
//}

// #include "GameFramework/Character.h"

void ANewCoin::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);

	if (!PlayerCharacter) return;

	if (GEngine) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Test!"));
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	AObstacleGamePlayerState* PlayerState = PlayerController != NULL ? PlayerController->GetPlayerState<AObstacleGamePlayerState>() : NULL;
	if (!PlayerState) return;

	PlayerState->AddCoins(5);


	Destroy();
}