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
	if (gtss::PcapDeviceList::isDeviceValid("any"))
	{
		GTSS_LOG("'any' device is valid.");
		return 0;
	}
	else
	{
		GTSS_LOG("'any' device is not valid.");
		return 1;
	}
}
