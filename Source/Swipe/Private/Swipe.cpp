//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "ISettingsModule.h"
#include "ISwipe.h"
#include "SwipeSettings.h"

#define LOCTEXT_NAMESPACE "Swipe"

class FSwipe : public ISwipe
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FSwipe, Swipe)

void FSwipe::StartupModule()
{
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Swipe",
			LOCTEXT("RuntimeSettingsName", "Swipe"),
			LOCTEXT("RuntimeSettingsDescription", "Configure the Swipe plugin"),
			GetMutableDefault<USwipeSettings>()
			);
	}
}


void FSwipe::ShutdownModule()
{
}



