/*
 * PcapDeviceList.cpp
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#include "PcapDeviceList.h"
#include "BindToScope.h"
#include "Log.h"

#include <algorithm>

#include <pcap.h>

namespace gtss {

bool PcapDeviceList::enumerate(std::vector<std::string>& output)
{
	pcap_if_t *devices = nullptr;
	char errors[PCAP_ERRBUF_SIZE]{ 0 };

	BIND_TO_SCOPE(devices);

    if (::pcap_findalldevs(&devices, errors) == PCAP_ERROR)
    {
    	GTSS_LOG("Error in pcap_findalldevs: " << errors);
        return false;
    }

    if (!output.empty())
    	output.clear();

    for(auto device = devices; device != nullptr; device = device->next)
    	output.push_back(device->name);

    if (output.empty())
    	GTSS_LOG("Enumerate succeed but no interfaces found. Are you root?");

    return true;

}

bool PcapDeviceList::isDeviceValid(const std::string& device)
{
	if (device.empty())
		return false;

	std::vector<std::string> devices;

	if (enumerate(devices) && std::find(devices.cbegin(), devices.cend(), device) != devices.cend())
		return true;
	else
		return false;
}

} /* namespace gtss */
