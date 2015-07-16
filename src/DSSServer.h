#include <sys/socket.h>
#include <netinet/in.h>

class DSSServer {
public:
private:
	int mSocket;
	int mBufferSize;
	unsigned short mPort;
	struct sockaddr_in mServerAddr;
};
