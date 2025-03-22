

//game
#include "SavesObjects/SavesManager.h"
#include "GameFramework/Actor.h"
#include "SavesObjects/AutoSaveTrigger.h"
#include "SavesObjects/SaveGameInstance.h"
#include "TimerManager.h"

#include "SlavicHorror/Public/HarvestCharacter.h"
#include "Inventory/Public/Components/InventoryComponent.h"
#include "QuestSystem/Public/QuestSystem.h"

//engine
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Gameframework/Actor.h"



USavesManager::USavesManager()
{
	static ConstructorHelpers::FClassFinder<AHarvestCharacter> BP_Player(TEXT("/Script/Engine.Blueprint'/Game/MovementSystem/Blueprints/BP_Player'")); 

	if (BP_Player.Succeeded())
	{

		BPPlayerClass = BP_Player.Class;

	}




}


/* Gets called when player is spawned */
void USavesManager::BeginPlay() 
{
	

	/*AutoSaveTriggerInstance = UGameplayStatics::GetActorOfClass(this, AAutoSaveTrigger::StaticClass()); 

	if (AutoSaveTriggerInstance)
	{
		AutoSaveTriggerInstance->TriggerActivatedDelegate.AddDynamic(this, &USavesManager::LaunchAutoSave); 
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("the trigger box ref is not valid")); 
	}*/




	//due to the function specifics, cannot deduce the original class of the AST actor
	// @TODO write a template function that will refer to the proper class


	GetAllObjectsOfClass<AAutoSaveTrigger>( AutoSaveTriggerRefs); 

	if (!AutoSaveTriggerRefs.IsEmpty())
	{
		for (auto ASTInstance : AutoSaveTriggerRefs)
		{

			if (Cast<AAutoSaveTrigger>(ASTInstance))
			{

				AutoSaveTriggerInstance = Cast<AAutoSaveTrigger>(ASTInstance); 
				AutoSaveTriggerInstance->TriggerActivatedDelegate.AddDynamic(this, &USavesManager::LaunchAutoSave); 

			}
			else
			{

				GEngine->AddOnScreenDebugMessage(1, 4.0f, FColor::Red, TEXT("The cast couldn't deduce autosave \
				trigger box original class. the launch AS delegate hasn't been bound")); 


			}

		}

	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 4.0f, FColor::Orange, TEXT("AST array is empty")); 


	}












	PlayerRef = UGameplayStatics::GetActorOfClass(this, BPPlayerClass); 

	if (!PlayerRef) { return; }

	if (PlayerRef->GetController())
	{
		InventoryRef = PlayerRef->GetController()->GetComponentByClass<UInventoryComponent>();
	}
	QuestSubsystemRef = PlayerRef->QuestSubsystemRef; 


	PlayerRef->OnDestroyed.AddDynamic(this, &USavesManager::LoadAutoSave); 



}




//this function is not getting called fsr 
void USavesManager::LaunchAutoSave(const AAutoSaveTrigger* AutoSaveTrigger)
{
	if (!PlayerRef || !InventoryRef || !QuestSubsystemRef) 
	{
		GEngine->AddOnScreenDebugMessage(2, 4.5f, FColor::Orange, TEXT("One of the references — inventory | quest | player is not valid, aborting")); 
		
		
		return;
	}

	
	SaveInstance = Cast<UAutoSave>(UGameplayStatics::CreateSaveGameObject(UAutoSave::StaticClass())); 

	if (!SaveInstance)
	{  
		GEngine->AddOnScreenDebugMessage(1, 4.0f, FColor::Red, TEXT("Save instance wasn't successfully initialized!"));
		
		return; 
	
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 4.0f, FColor::Blue, TEXT("Save instance was initialized successfully!"));



	}
	
	//creating a SaveInstance instance and keeping it in a slot

	//plain character data
	SaveInstance->SavedTransform = PlayerRef->GetActorTransform(); 
	SaveInstance->SavedHealth = PlayerRef->GetHealth(); 
	
	//inventory
	SaveInstance->SavedBasicContainer = InventoryRef->GetBasicContainer(); 
	SaveInstance->SavedSpecialContainer = InventoryRef->GetSpecialContainer(); 
	SaveInstance->SavedHotbarContainer = InventoryRef->GetHotbarContainer(); 
	
	//quests
	SaveInstance->SavedActiveQuests = QuestSubsystemRef->GetActiveQuests(); 
	SaveInstance->SavedCompletedQuests = QuestSubsystemRef->GetCompletedQuests(); 

	//Ghoul
	//@TODO implement ghoul's activity rate someday in the future 



	//saving the instance to the slot
	UGameplayStatics::AsyncSaveGameToSlot(SaveInstance, SlotName, 0); 


	GEngine->AddOnScreenDebugMessage(1, 4.0f, FColor::Black, TEXT("Running launch autosave successfully walked throuhg the entire function!"));



}




void USavesManager::LoadAutoSave(AActor* OutActor) 
{
	
	FAsyncLoadGameFromSlotDelegate AsynchLoadDelegate;

	UGameplayStatics::AsyncLoadGameFromSlot(SlotName, 0, AsynchLoadDelegate); 



	FTimerHandle TimerHandle; 


	GetWorld()->GetTimerManager().SetTimer(TimerHandle,this, &USavesManager::RespawnActor, 4.0f, false); 


	

}

void USavesManager::RespawnActor() 
{
	if (!SaveInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("SaveInstance is not valid aborting respawn"));
		return;
	} 
	if (!GetWorld()) { return; }

	FActorSpawnParameters RespawnInfo;


	 CtrlRef = GetWorld()->GetFirstPlayerController();

	 if (!CtrlRef) { return; }

	
	TSoftObjectPtr<AHarvestCharacter> NewPlayer =  GetWorld()->SpawnActor<AHarvestCharacter>(BPPlayerClass, SaveInstance->SavedTransform, RespawnInfo); 
	
	if (NewPlayer )
	{
		CtrlRef->Possess(NewPlayer.Get()); 



	}





}



//
//void USavesManager::OnCharacterDeath(AActor* OutActor)
//{
//
//
//
//}
