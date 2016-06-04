/*
 * EthernetTcpPacketSniffer.h
 *
 *  Created on: Jun 2, 2016
 *      Author: sepehr
 */

#ifndef ETHERNETTCPPACKETSNIFFER_H_
#define ETHERNETTCPPACKETSNIFFER_H_

#include "PacketSniffer.h"

namespace gtss {

class EthernetTcpPacketSniffer : public PacketSniffer {
public:
	EthernetTcpPacketSniffer(PcapDevice& device);
	virtual ~EthernetTcpPacketSniffer();

protected:
	virtual void onPacket(const pcap_pkthdr *h, const u_char *bytes) override final;
	virtual void onTcpPayload(const u_char * payload, int size) = 0;
};

} /* namespace gtss */

#endif /* ETHERNETTCPPACKETSNIFFER_H_ */
