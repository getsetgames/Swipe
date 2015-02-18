//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "SwipePrivatePCH.h"

DEFINE_LOG_CATEGORY(LogSwipe);

class FSwipe : public ISwipe
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FSwipe, Swipe )



void FSwipe::StartupModule()
{
}


void FSwipe::ShutdownModule()
{
}



