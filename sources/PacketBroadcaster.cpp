/*
 * PacketBroadcaster.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: sepehr
 */

#include "PacketBroadcaster.h"
#include "UdpClient.h"

namespace gtss {

PacketBroadcaster::PacketBroadcaster(PcapDevice& dev, UdpClient& client)
	: EthernetTcpPacketSniffer(dev)
	, mUdpClient(client)
{}

PacketBroadcaster::~PacketBroadcaster() {
	// TODO Auto-generated destructor stub
}

void PacketBroadcaster::onTcpPayload(const u_char* payload, int size) {
	mUdpClient.send(payload, size);
}

} /* namespace gtss */
