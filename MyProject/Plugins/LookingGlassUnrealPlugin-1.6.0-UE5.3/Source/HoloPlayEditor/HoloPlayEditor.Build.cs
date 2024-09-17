using UnrealBuildTool;

public class HoloPlayEditor : ModuleRules
{
	public HoloPlayEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.NoPCHs;

        PublicIncludePaths.AddRange(
			new string[] {
			}
			);


		PrivateIncludePaths.AddRange(
			new string[] {
			}
			);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
            }
            );


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Json",
				"JsonUtilities",
				"HTTP",
				"DetailCustomizations",
				"DesktopWidgets",
				"MovieSceneCapture",
				"Slate",
				"SlateCore",
                "InputCore",
                "Projects",
				"PropertyEditor",
				"UnrealEd",
				"EditorStyle",
				"MainFrame",
				"LevelEditor",
                "Settings",
#if UE_5_0_OR_LATER
				"ToolMenus",
				"ToolWidgets",
#endif
                "HoloPlayRuntime"
            }
			);
	}
}
