/*
 * Log.h
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#ifndef LOG_H_
#define LOG_H_

#include <string>
#include <thread>
#include <sstream>

namespace gtss {

/*!
 * @fn    log
 * @brief A very basic thread-safe logger.
 * @note  Users should prefer using convenience GTSS_LOG macro.
 */
void log(const std::string& msg);

/*! A convenience macro for gtss::log. Input can be either string or stream
constructed with << operator. NOTE: an end line will be automatically appended. */
#ifndef GTSS_LOG
#   define GTSS_LOG(buf) { std::stringstream ss; ss << "[GTSS]" << "[" << std::this_thread::get_id() << "] " << buf << std::endl; gtss::log(ss.str()); }
#endif

} /* namespace gtss */

#endif /* LOG_H_ */
