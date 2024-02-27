// Copyright (c) 2024 Sentry. All Rights Reserved.

#include "SentryTowerPawn.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ASentryTowerPawn::ASentryTowerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetRelativeRotation(FRotator(-45.0f, -45.0f, 0.0));
	SpringArmComponent->TargetArmLength = 2000.0f;
	SpringArmComponent->bDoCollisionTest = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	TowerBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TowerBase"));
	TowerBase->SetupAttachment(RootComponent);
	TowerMid = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TowerMid"));
	TowerMid->SetupAttachment(TowerBase, FName("TopSocket"));
	TowerTop = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TowerTop"));
	TowerTop->SetupAttachment(TowerMid, FName("TopSocket"));

	Turret = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret"));
	Turret->SetupAttachment(TowerTop, FName("TopSocket"));
}

// Called when the game starts or when spawned
void ASentryTowerPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASentryTowerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASentryTowerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

