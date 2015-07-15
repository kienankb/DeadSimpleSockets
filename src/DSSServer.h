class DSSServer {
public:
private:
	int mSocket;
	int mBufferSize;
	unsigned short mPort;
	struct sockaddr_in mServerAddr;
};
