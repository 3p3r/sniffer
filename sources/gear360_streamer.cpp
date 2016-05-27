//============================================================================
// Name        : gear360_streamer.cpp
// Author      : Sepehr Laal
// Version     :
// Copyright   : Copyright 2016 all rights reserved. Take a look at LICENSE file
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "PcapDeviceList.h"
#include "Log.h"

int main()
{
	std::vector<std::string> devices;

	if (gtss::PcapDeviceList::enumerate(devices))
	{
		for(const auto& device : devices)
			GTSS_LOG("Device found: " << device);

		GTSS_LOG("Device enumeration succeed.");
		return 0;
	}
	else
	{
		GTSS_LOG("Device enumeration failed.");
		return 1;
	}
}
