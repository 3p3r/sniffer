/*
 * PcapDevice.h
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#ifndef PCAPDEVICE_H_
#define PCAPDEVICE_H_

#include <string>
#include <memory>

using pcap_t = struct pcap;

namespace gtss {

class PcapDevice {
public:
	PcapDevice();
	~PcapDevice();

	bool open(const std::string& device, const std::string& filter);
	bool isOpen() const;
	void close();

	const std::string& getName() const;
	void setName(const std::string& name);

	pcap_t* getDevice() const;

private:
	std::string mName;
	pcap_t*		mDevice;
};

} /* namespace gtss */

#endif /* PCAPDEVICE_H_ */
