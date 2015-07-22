#include <sys/socket.h>
#include <netinet/in.h>

class DSSClient {
public:
	DSSClient();
	DSSClient(char* address, unsigned short port);
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
