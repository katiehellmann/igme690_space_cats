// Define this to build plugin as an engine plugin, even when build is executed from .uproject
// Todo: can remove code for IsEnginePlugin() == false (including CopyToProjectBinaries function)
#define FORCE_ENGINE_PLUGIN_BUILD

namespace UnrealBuildTool.Rules
{
    using System;
    using System.IO;
    using System.Collections.Generic;

    public class HoloPlayRuntime : ModuleRules
    {
		private bool IsEnginePlugin()
		{
#if FORCE_ENGINE_PLUGIN_BUILD
			return true;
#else
			return Path.GetFullPath(ModuleDirectory).Contains("\\Engine\\Plugins\\");
#endif
		}

		private string ModulePath
        {
            get { return ModuleDirectory; }
        }

        private string ThirdPartyPath
        {
            get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); }
        }

        private string BinariesPath
        {
            get { return Path.GetFullPath(Path.Combine(ModulePath, "../../Binaries/")); }
        }

        public string GetUProjectPath()
        {
            return Path.Combine(ModuleDirectory, "../../../..");
        }

        private void CopyToProjectBinaries(string Filepath, ReadOnlyTargetRules Target)
        {
            System.Console.WriteLine("UE4 is: " + Path.GetFullPath(GetUProjectPath()));

            string BinariesDir = Path.Combine(GetUProjectPath(), "Binaries", Target.Platform.ToString());
            string Filename = Path.GetFileName(Filepath);

            //convert relative path
            string FullBinariesDir = Path.GetFullPath(BinariesDir);

            if (!Directory.Exists(FullBinariesDir))
            {
                Directory.CreateDirectory(FullBinariesDir);
            }

            string FullBinaryFilepath = Path.Combine(FullBinariesDir, Filename);
            if (!File.Exists(FullBinaryFilepath))
            {
                System.Console.WriteLine("HoloPlay: Copied from " + Filepath + ", to " + FullBinaryFilepath);
                File.Copy(Filepath, FullBinaryFilepath, true);
            }
        }


        public HoloPlayRuntime(ReadOnlyTargetRules Target) : base(Target)
        {
            System.Console.WriteLine("Build for HoloPlayCore");

            DefaultBuildSettings = BuildSettingsVersion.V1;

            PCHUsage = PCHUsageMode.NoPCHs;
            bPrecompile = true;
            bEnableExceptions = true;


            PublicIncludePaths.AddRange(
                new string[] {
                    // ... add public include paths required here ...
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
                    "InputCore",
                }
                );


            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "ApplicationCore",
                    "RenderCore",
                    "RHI",
                    "CoreUObject",
                    "Engine",
                    "Slate",
                    "SlateCore",
                    "Projects",
                    "HeadMountedDisplay",
                    "ImageWrapper",
                    "EngineSettings",
                    "MovieSceneCapture",
                    "ImageWriteQueue",
                    "AVIWriter",
                    "Renderer",

#if UE_5_1_OR_LATER
#else
					"ImageWriteQueue",
#endif
                    "Json"
                }
                );

            if (Target.bBuildEditor == true)
            {
                PrivateDependencyModuleNames.Add("UnrealEd");
				PrivateDependencyModuleNames.Add("Sequencer");
			}

			string LibraryPlatformFolder = string.Empty;
            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                LibraryPlatformFolder = "Win64";
            }
            else if (Target.Platform == UnrealTargetPlatform.Mac)
            {
                LibraryPlatformFolder = "osx";
            }
            else if (Target.Platform == UnrealTargetPlatform.Linux)
            {
                LibraryPlatformFolder = "linux64";
            }

            string HoloPlayDirectoryName = "HoloPlayCore";


            string IncludePath = Path.Combine(ThirdPartyPath, HoloPlayDirectoryName, "Include");
            PublicIncludePaths.Add(IncludePath);

            string LibraryPath = Path.Combine(ThirdPartyPath, HoloPlayDirectoryName, "Lib", LibraryPlatformFolder);
            string DLLPath = Path.Combine(ThirdPartyPath, HoloPlayDirectoryName, "Bin", LibraryPlatformFolder);


            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                string HoloPlayLibName = "HoloPlayCore";

                //Lib
                PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, HoloPlayLibName + ".lib"));

                //DLL
                string PluginDLLPath = Path.Combine(DLLPath, HoloPlayLibName + ".dll");

				if (IsEnginePlugin())
				{
					// Copy the dll next to the plugin
					RuntimeDependencies.Add("$(BinaryOutputDir)/" + HoloPlayLibName + ".dll", PluginDLLPath);
				}
				else
				{
					System.Console.WriteLine("Project plugin detected, using dll at " + PluginDLLPath);

					// This copy DLL from Plugin\ThirdParty\HoloPlay\Bin\ to UE4Project\Binaries\Win64\
					CopyToProjectBinaries(PluginDLLPath, Target);

					string ProjectDLLFile = Path.GetFullPath(Path.Combine(GetUProjectPath(), "Binaries", LibraryPlatformFolder, HoloPlayLibName + ".dll"));
					// Request copy DLL from UE4Project\Binaries\Win64\ to UE4Build\Binaries\Win64\
					RuntimeDependencies.Add(ProjectDLLFile);
				}

                // Delay load DLLs - typically used for External(third party) modules
                // We need to delay the Lib in order to Build, otherwise it will lock HoloPlay.dll from the UE4Project\Binaries\Win64\
                PublicDelayLoadDLLs.Add(HoloPlayLibName + ".dll");
            }
        }
    }
}
