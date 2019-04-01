//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

using UnrealBuildTool;

public class Swipe : ModuleRules
{
	public Swipe(ReadOnlyTargetRules Target) : base(Target)
    {

        bEnforceIWYU = false;
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
			new string[] {
                "Swipe/Public",
                "Swipe/Classes"
				// ... add public include paths required here ...
			}
			);

		PrivateIncludePaths.AddRange(
			new string[] {
				"Swipe/Private",
				// ... add other private include paths required here ...
			}
			);

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine"
				// ... add other public dependencies that you statically link with here ...
			}
			);

		PrivateIncludePathModuleNames.AddRange(
			new string[] {
				"Settings"
			}
			);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...
			}
			);

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}

