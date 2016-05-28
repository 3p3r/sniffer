/*
 * UdpClient.h
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#ifndef UDPCLIENT_H_
#define UDPCLIENT_H_

#include <string>

#include <netinet/in.h>

namespace gtss {

class UdpClient {
public:
	UdpClient();
	~UdpClient();

	bool setEndpoint(const std::string& address, short port);
	void send(const std::string& message);
	void send(const void* data, size_t size);
	bool isValid();
	void close();

private:
	sockaddr_in mEndpoint;
	int 		mSocketFd;
	bool		mValid;
};

} /* namespace gtss */

#endif /* UDPCLIENT_H_ */
