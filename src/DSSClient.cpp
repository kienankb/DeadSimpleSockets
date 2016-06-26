#include "DSSClient.h"
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

DSSClient::DSSClient() {
	mSocket = 0;
	mBufferSize = 0;
	mPort = 0;
	mDomain = 0;
	mType = 0;
	mProtocol = 0;
}

// Constructor takes in an address and a port, but
// otherwise defaults to internet, TCP, and some other options
DSSClient::DSSClient(std::string address, unsigned short port) {
	mAddress = address;
	mPort = port;
	mDomain = AF_INET;
	mType = SOCK_STREAM;
	mProtocol = 0;
	mBufferSize = 1024;
}

int DSSClient::connect() {
	mSocket = socket(mDomain, mType, mProtocol);
	if (mSocket < 0) {
		return -1;
	}
	mServerAddr.sin_family = mDomain;
	mServerAddr.sin_port = htons(mPort);
	mServerAddr.sin_addr.s_addr = inet_addr(mAddress.c_str());
	memset(&mServerAddr.sin_zero, 0, sizeof(mServerAddr.sin_zero));
	int connectVal = connect(mSocket, (struct sockaddr*)&mServerAddr, sizeof mServerAddr);
	if (connectVal < 0) {
		return -1;
	}
	return 0;
}

int DSSClient::send(std::string data)
{
	int bytesSent = send(mSocket, data.c_str(), data.length() + 1, 0);
	return bytesSent;
}
