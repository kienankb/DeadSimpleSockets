#include "DSSClient.h"
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//
// Default constructor, we'll zero everything out
//
DSSClient::DSSClient() {
	mSocket = 0;
	mBufferSize = 0;
	mPort = 0;
	mDomain = 0;
	mType = 0;
	mProtocol = 0;
}

//
// Simplest constructor; takes in an address and a port, but
// otherwise defaults to internet, TCP, and some others
//
DSSClient::DSSClient(std::string address, unsigned short port) {
	mAddress = address;
	mPort = port;
	mDomain = AF_INET;
	mType = SOCK_STREAM;
	mProtocol = 0;
	mBufferSize = 1024;
}

int DSSClient::initialize() {
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
