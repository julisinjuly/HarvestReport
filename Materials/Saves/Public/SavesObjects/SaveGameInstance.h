// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveGameInstance.generated.h"

class UItemBase; 
class UQuestBase; 
class UItemContainer; 


/**
 * 
 */


UCLASS()
class SAVES_API UAutoSave : public USaveGame
{
	GENERATED_BODY()

public: 

	UPROPERTY()
	FString SlotName = "AutoSave Slot"; 

	UPROPERTY()
	FTransform SavedTransform; 

	UPROPERTY()
	float SavedHealth;

	UPROPERTY()
	int8 SavedGhoulAggressivenessRate;

	UPROPERTY()
	TArray<UItemBase*>SavedInventoryContents;

	UPROPERTY()
	TArray<UQuestBase*> SavedActiveQuests; 

	UPROPERTY()
	TArray<UQuestBase*> SavedCompletedQuests; 

	UPROPERTY()
	UItemContainer* SavedBasicContainer; 

	UPROPERTY()
	UItemContainer* SavedSpecialContainer; 

	UPROPERTY()
	UItemContainer* SavedHotbarContainer; 

	
};



UCLASS()
class SAVES_API UManualSave : public USaveGame
{
	GENERATED_BODY()

public: 
	
	UPROPERTY()
	FString SlotName = "ManualSave Slot"; 
	
	UPROPERTY()
	FTransform SavedTransform;

	UPROPERTY()
	float SavedHealth;

	UPROPERTY()
	int8 SavedGhoulAggressivenessRate;

	UPROPERTY()
	TArray<UItemBase*> SavedInventoryContents;

	UPROPERTY()
	TArray<UQuestBase*> SavedActiveQuests;

	UPROPERTY()
	TArray<UQuestBase*> SavedCompletedQuests;

	UPROPERTY()
	UItemContainer* SavedBasicContainer;

	UPROPERTY()
	UItemContainer* SavedSpecialContainer;

	UPROPERTY()
	UItemContainer* SavedHotbarContainer; 






};