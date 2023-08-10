using UnrealBuildTool;
using System.IO;
using System;

public class InlineDispenser : ModuleRules
{
	public InlineDispenser(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"OnlineSubsystem",
			"OnlineSubsystemUtils",
			"OnlineSubsystemNULL",
			"SignificanceManager",
			"PhysX",
			"APEX",
			"PhysXVehicles",
			"ApexDestruction",
			"AkAudio",
			"ReplicationGraph",
			"UMG",
			"AIModule",
			"NavigationSystem",
			"AssetRegistry",
			"GameplayTasks",
			"AnimGraphRuntime",
			"Slate",
			"SlateCore",
			"Json",
			"HTTP",
		});

		if (Target.Type == TargetRules.TargetType.Editor)
		{
			PublicDependencyModuleNames.AddRange(new string[]
			{
				"OnlineBlueprintSupport",
				"AnimGraph"
			});
		}

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"FactoryGame",
			"SML",
		});
	}
}