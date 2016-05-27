/*
 * PacketSniffer.h
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#ifndef PACKETSNIFFER_H_
#define PACKETSNIFFER_H_

#include <sys/types.h>

struct pcap_pkthdr;

namespace gtss {

class PcapDevice;
class PacketSniffer {
public:
	PacketSniffer(PcapDevice& device);
	virtual ~PacketSniffer() { /* no-op */ }
	void startSniffing();

protected:
	virtual void onPacket(const struct pcap_pkthdr *h, const u_char *bytes) = 0;
	static void onPcapLoopCallback(PacketSniffer* user, const pcap_pkthdr *h, const u_char *bytes);

private:
	PcapDevice& mDevice;
};

} /* namespace gtss */

#endif /* PACKETSNIFFER_H_ */
