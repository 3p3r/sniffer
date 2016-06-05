//============================================================================
// Name        : gear360_streamer.cpp
// Author      : Sepehr Laal
// Version     :
// Copyright   : Copyright 2016 all rights reserved. Take a look at LICENSE file
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "PacketBroadcaster.h"
#include "PcapDevice.h"
#include "UdpClient.h"
#include "Log.h"

#include <pcap.h>

using namespace gtss;

int main()
{
	PcapDevice device;
	UdpClient client;

	if (!client.setEndpoint("192.168.0.9", 5000))
	{
		GTSS_LOG("Unable to set UDP endpoint.");
		return 0;
	}


	if (device.open("lo", "src host 127.0.0.1 and src port 10000"))
	{
		GTSS_LOG("Device opened with filter specified.");

		PacketBroadcaster sniffer(device, client);
		sniffer.startSniffing();

		return 0;
	}
	else
	{
		GTSS_LOG("Device failed to open with filter specified.");
		return 1;
	}
}
