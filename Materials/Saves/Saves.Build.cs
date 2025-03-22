using UnrealBuildTool;

public class Saves: ModuleRules
{
	public Saves(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "SlateCore", "Slate", "UMG",  "MotionWarping", "Interaction", "Inventory", "Ghoul", "QuestSystem"});

        PrivateDependencyModuleNames.AddRange(new string[] { "SlavicHorror" });

        CircularlyReferencedDependentModules.Add("SlavicHorror");


    }
}
