#include <sys/socket.h>
#include <netinet/in.h>

class DSSClient {
public:
	DSSClient();
	DSSClient(char* address, unsigned short port);
	int getSocket() { return mSocket; }
	int getBufferSize() { return mBufferSize; }
	char* getAddress() { return mAddress; }
	unsigned short getPort() { return mPort; }
	int getDomain() { return mDomain; }
	int getType() { return mType; }
	int getProtocol() { return mProtocol; }
private:
	int mSocket;
	int mBufferSize;
	char* mAddress;
	unsigned short mPort;
	struct sockaddr_in mServerAddr;
	int mDomain;
	int mType;
	int mProtocol;
};
