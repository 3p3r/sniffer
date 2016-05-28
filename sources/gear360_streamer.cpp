//============================================================================
// Name        : gear360_streamer.cpp
// Author      : Sepehr Laal
// Version     :
// Copyright   : Copyright 2016 all rights reserved. Take a look at LICENSE file
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "PacketSniffer.h"
#include "PcapDevice.h"
#include "UdpClient.h"
#include "Log.h"

#include <pcap.h>

using namespace gtss;

namespace {

class PacketBroadcaster final : public PacketSniffer {
public:
	PacketBroadcaster(PcapDevice& dev, UdpClient& client)
		: PacketSniffer(dev)
		, mUdpClient(client)
	{}

protected:
	void onPacket(const pcap_pkthdr *h, const u_char *bytes) override
	{
		mUdpClient.send(bytes, h->caplen);
	}

private:
	UdpClient& mUdpClient;
};

}

int main()
{
	PcapDevice device;
	UdpClient client;

	if (!client.setEndpoint("192.168.1.168", 5000))
	{
		GTSS_LOG("Unable to set UDP endpoint.");
		return 0;
	}


	if (device.open("any", "tcp"))
	{
		GTSS_LOG("Device opened with filter specified.");

		PacketBroadcaster tracer(device, client);
		tracer.startSniffing();

		return 0;
	}
	else
	{
		GTSS_LOG("Device failed to open with filter specified.");
		return 1;
	}
}
