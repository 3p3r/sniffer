/*
 * BindToScope.cpp
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#include "BindToScope.h"

#include <pcap.h>

namespace gtss {

template<> BindToScope<pcap_if_t>::~BindToScope() { ::pcap_freealldevs(pointer); pointer = nullptr; }

} /* namespace gtss */
