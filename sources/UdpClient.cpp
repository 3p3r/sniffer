/*
 * UdpClient.cpp
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#include "Log.h"
#include "UdpClient.h"

#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

namespace gtss {

UdpClient::UdpClient()
	: mEndpoint({0})
	, mSocketFd(0)
	, mValid(false)
{}

UdpClient::~UdpClient() {
	close();
}

bool UdpClient::setEndpoint(const std::string& address, short port)
{
	close();

	if ((mSocketFd = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		GTSS_LOG("socket SOCK_DGRAM construction failed.");
		return false;
	}

	mEndpoint.sin_family = AF_INET;
	mEndpoint.sin_port = ::htons(port);

    if (::inet_aton(address.c_str(), &mEndpoint.sin_addr) == 0)
    {
    	GTSS_LOG("inet_aton() failed.");
    	return false;
    }

    mValid = true;
    return true;
}

bool UdpClient::isValid()
{
	return mValid;
}

void UdpClient::send(const std::string& message)
{
	send(message.c_str(), message.size());
}

void UdpClient::send(const void* data, size_t size)
{
	if (!isValid())
		return;

	::sendto(mSocketFd, data, size, 0, reinterpret_cast<sockaddr*>(&mEndpoint), sizeof(mEndpoint));
}

void UdpClient::close()
{
	if (!isValid())
		return;

	if (mSocketFd > 0)
		::close(mSocketFd);

	mSocketFd = 0;
	mEndpoint = { 0 };
	mValid = false;
}

} /* namespace gtss */
