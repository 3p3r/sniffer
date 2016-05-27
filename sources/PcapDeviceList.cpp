/*
 * PcapDeviceList.cpp
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#include "PcapDeviceList.h"
#include "BindToScope.h"
#include "Log.h"

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

    return true;

}

} /* namespace gtss */
