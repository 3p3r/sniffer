/*
 * PcapDevice.cpp
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#include "Log.h"
#include "PcapDevice.h"
#include "BindToScope.h"
#include "PcapDeviceList.h"

#include <pcap.h>

namespace gtss {

PcapDevice::PcapDevice()
	: mDevice(nullptr)
{}

PcapDevice::~PcapDevice()
{
	if (isOpen())
		close();
}

bool PcapDevice::open(const std::string& device, const std::string& filter)
{
	if (!PcapDeviceList::isDeviceValid(device))
		return false;

	close();
	char errbuf[PCAP_ERRBUF_SIZE]{ 0 };
	mDevice = ::pcap_open_live(device.c_str(), BUFSIZ, 0,-1, errbuf);

	if (mDevice != nullptr)
	{
		struct bpf_program fp;

		struct bpf_program *fpp = &fp;
		BIND_TO_SCOPE(fpp);

	    if(::pcap_compile(mDevice, &fp, filter.c_str(), 0, PCAP_NETMASK_UNKNOWN) == PCAP_ERROR)
	    {
	    	GTSS_LOG("pcap_compile failed.");
	        return false;
	    }

	    if(::pcap_setfilter(mDevice, &fp) == PCAP_ERROR)
	    {
	    	GTSS_LOG("pcap_setfilter failed.");
	    	return false;
	    }

		mName = device;
		return true;
	}
	else
	{
		GTSS_LOG("pcap_open_live returned empty " << errbuf);
		return false;
	}
}

void PcapDevice::close()
{
	if (isOpen())
	{
		GTSS_LOG("pcap_close called on device.");

		::pcap_close(mDevice);
		mDevice = nullptr;
	}

	if (!getName().empty())
		mName.clear();
}

const std::string& PcapDevice::getName() const
{
	return mName;
}

bool PcapDevice::isOpen() const
{
	return mDevice != nullptr;
}

void PcapDevice::setName(const std::string& name)
{
	if (getName() == name)
		return;

	mName = name;
}

pcap_t* PcapDevice::getDevice() const
{
	return mDevice;
}

} /* namespace gtss */
