// Fill out your copyright notice in the Description page of Project Settings.


#include "SavesObjects/AutoSaveTrigger.h"
#include "Components/BoxComponent.h"


// Sets default values
AAutoSaveTrigger::AAutoSaveTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));



}

void AAutoSaveTrigger::BeginPlay()
{
	Super::BeginPlay();

	

	OnActorBeginOverlap.AddUniqueDynamic(this, &AAutoSaveTrigger::OnAutoSaveTriggered); 
	



	
}

void AAutoSaveTrigger::OnAutoSaveTriggered(AActor* ThisActor, AActor* OverlappedActor)
{
	//implement handling the logic to the manager here 

	TriggerActivatedDelegate.Broadcast(this);

	GEngine->AddOnScreenDebugMessage(1, 4.0f, FColor::Magenta, TEXT("Collision trigger works"));
	



}

void AAutoSaveTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

