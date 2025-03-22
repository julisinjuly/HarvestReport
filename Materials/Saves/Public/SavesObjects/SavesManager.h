#pragma once

//engine
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UObject/UObjectIterator.h"
#include "UObject/UObjectGlobals.h"


//game
#include "SavesManager.generated.h"


class AAutoSaveTrigger; 
class AHarvestCharacter;
class UInventoryComponent; 
class UQuestSubsystem; 
class UAutoSave; 


UCLASS(Blueprintable)
class SAVES_API USavesManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	USavesManager(); 


	//FUNCTIONS	: private
// ‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰
// ‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰


	UFUNCTION(BlueprintCallable)
	void LaunchAutoSave(const AAutoSaveTrigger* AutoSaveTrigger); 


	UFUNCTION(BlueprintCallable)
	void LoadAutoSave(AActor* OutActor); 

	
	void RespawnActor(); 

	//void OnCharacterDeath(AActor* OutActor);


	
//VARIABLES: private
// ‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰
// ‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰

	UAutoSave* SaveInstance = nullptr; 


//REFRENCES: private
// ‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰
// ‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰

	TSubclassOf<AHarvestCharacter> BPPlayerClass;
	TSoftObjectPtr<AHarvestCharacter> PlayerRef;
	TSoftObjectPtr<APlayerController> CtrlRef;
	TSoftObjectPtr<UInventoryComponent> InventoryRef = nullptr;
	TSoftObjectPtr<UQuestSubsystem> QuestSubsystemRef = nullptr;
	TArray<AAutoSaveTrigger*> AutoSaveTriggerRefs; 
	TSoftObjectPtr<AAutoSaveTrigger> AutoSaveTriggerInstance = nullptr; 




	FString SlotName = " "; 
	
	template <typename T> void GetAllObjectsOfClass(TArray<T*>& OutObjects, bool bIncludeDerivedClasses = true)
	{
		OutObjects.Empty();

		for (TObjectIterator<T> It; It; ++It)
		{

			if (It)
			{
				OutObjects.Add(*It);
			}
		}
	}



//FUNCTIONS	: public
// ‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰
// ‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰ ༻ ‿̩͙‿‿̩͙‿ ༺ ♰

public: 
	/* Gets called when player is spawned */
	void BeginPlay(); 



};
