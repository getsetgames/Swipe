//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "Modules/ModuleManager.h"

class ISwipe : public IModuleInterface
{

public:

	static inline ISwipe& Get()
	{
		return FModuleManager::LoadModuleChecked< ISwipe >("Swipe");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("Swipe");
	}
};

