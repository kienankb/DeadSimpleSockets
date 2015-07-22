#include <sys/socket.h>
#include <netinet/in.h>

class DSSClient {
public:
	DSSClient::DSSClient();
	DSSClient::DSSClient(char* address, unsigned short port);
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
