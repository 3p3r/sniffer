/*
 * PacketSniffer.cpp
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#include "PcapDevice.h"
#include "PacketSniffer.h"

#include <pcap.h>

namespace gtss {

PacketSniffer::PacketSniffer(PcapDevice& device)
	: mDevice(device)
{}

void PacketSniffer::startSniffing()
{
	if (mDevice.isOpen())
		::pcap_loop(mDevice.getDevice(), 0, reinterpret_cast<pcap_handler>(onPcapLoopCallback), reinterpret_cast<u_char *>(this));
}

void PacketSniffer::onPcapLoopCallback(PacketSniffer* user,
		const struct pcap_pkthdr* h, const u_char* bytes)
{
	user->onPacket(h, bytes);
}

} /* namespace gtss */
