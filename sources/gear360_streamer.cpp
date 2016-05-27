//============================================================================
// Name        : gear360_streamer.cpp
// Author      : Sepehr Laal
// Version     :
// Copyright   : Copyright 2016 all rights reserved. Take a look at LICENSE file
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "PcapDevice.h"
#include "Log.h"

int main()
{
	using namespace gtss;

	PcapDevice device;

	if (device.open("any", "host 127.0.0.1"))
	{
		GTSS_LOG("Device opened with filter specified.");
		return 0;
	}
	else
	{
		GTSS_LOG("Device failed to open with filter specified.");
		return 1;
	}
}
