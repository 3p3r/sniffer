/*
 * Log.cpp
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#include "Log.h"

#include <mutex>
#include <iostream>

namespace gtss {


void log(const std::string& msg) {
    static std::mutex guard;
    std::lock_guard<decltype(guard)> lock(guard);
    std::cout << msg;
}

} /* namespace gtss */
