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
#include "Log.h"

#include <pcap.h>

using namespace gtss;

namespace {

class PacketSizeTracer final : public PacketSniffer {
public:
	PacketSizeTracer(PcapDevice& dev) : PacketSniffer(dev) {}

protected:
	void onPacket(const pcap_pkthdr *h, const u_char *bytes) override
	{
		GTSS_LOG("Packet sniffed. Size: " << h->len);
	}
};

}

int main()
{
	PcapDevice device;

	if (device.open("any", "tcp"))
	{
		GTSS_LOG("Device opened with filter specified.");

		PacketSizeTracer tracer(device);
		tracer.startSniffing();

		return 0;
	}
	else
	{
		GTSS_LOG("Device failed to open with filter specified.");
		return 1;
	}
}
