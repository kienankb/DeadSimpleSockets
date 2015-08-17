#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

class DSSClient {
public:
	// Constructors
	DSSClient();
	DSSClient(std::string address, unsigned short port);

	// Get/sets
	int getSocket() { return mSocket; }
	int getBufferSize() { return mBufferSize; }
	std::string getAddress() { return mAddress; }
	unsigned short getPort() { return mPort; }
	int getDomain() { return mDomain; }
	int getType() { return mType; }
	int getProtocol() { return mProtocol; }
	void setBufferSize(int bufferSize) { mBufferSize = bufferSize; }
	void setAddress(std::string address) { mAddress = address; }
	void setPort(unsigned short port) { mPort = port; }
	void setDomain(int domain) { mDomain = domain; }
	void setType(int type) { mType = type; }
	void setProtocol(int protocol) { mProtocol = protocol; }

	// Connection and usage
	int Connect();
	int Send(std::string data);

private:
	int mSocket;
	int mBufferSize;
	std::string mAddress;
	unsigned short mPort;
	struct sockaddr_in mServerAddr;
	int mDomain;
	int mType;
	int mProtocol;
};
