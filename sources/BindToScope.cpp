/*
 * BindToScope.cpp
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#include "BindToScope.h"

#include <pcap.h>

struct bpf_program;

namespace gtss {

template<> BindToScope<pcap_if_t>::~BindToScope() 	{ ::pcap_freealldevs(pointer); pointer = nullptr; }
template<> BindToScope<bpf_program>::~BindToScope() { ::pcap_freecode(pointer); pointer = nullptr; }

} /* namespace gtss */
