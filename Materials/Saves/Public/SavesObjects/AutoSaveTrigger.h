// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AutoSaveTrigger.generated.h"

class UBoxComponent; 

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTriggerActivatedSignature, const AAutoSaveTrigger*, ASInstance); 

UCLASS()
class SAVES_API AAutoSaveTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	AAutoSaveTrigger();
	
	virtual void Tick(float DeltaTime) override;


	FTriggerActivatedSignature TriggerActivatedDelegate; 

	

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable , Category = "Autosaves")
	void OnAutoSaveTriggered(AActor* ThisActor, AActor* OverlappedActor); 


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NativeComponents")
	UBoxComponent* BoxCollision;	


};
