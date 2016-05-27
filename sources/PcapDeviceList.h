/*
 * PcapDeviceList.h
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#ifndef PCAPDEVICELIST_H_
#define PCAPDEVICELIST_H_

#include <vector>
#include <string>

namespace gtss {

class PcapDeviceList {
public:
	static bool enumerate(std::vector<std::string>& devices);
	static bool isDeviceValid(const std::string& device);
};

} /* namespace gtss */

#endif /* PCAPDEVICELIST_H_ */
