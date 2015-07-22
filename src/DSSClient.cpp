#include "DSSClient.h"

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
