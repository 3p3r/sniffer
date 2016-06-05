/*
 * PacketBroadcaster.h
 *
 *  Created on: Jun 4, 2016
 *      Author: sepehr
 */

#ifndef PACKETBROADCASTER_H_
#define PACKETBROADCASTER_H_

#include "EthernetTcpPacketSniffer.h"

namespace gtss {

class UdpClient;
class PcapDevice;

class PacketBroadcaster final : public EthernetTcpPacketSniffer {
public:
	PacketBroadcaster(PcapDevice& dev, UdpClient& client);
	virtual ~PacketBroadcaster();

protected:
	void onTcpPayload(const u_char * payload, int size) override final;

private:
	UdpClient& mUdpClient;
};

} /* namespace gtss */

#endif /* PACKETBROADCASTER_H_ */
