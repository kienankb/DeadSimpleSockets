#include "../src/DSSClient.h"

int main(int argc, char const *argv[])
{
	DSSClient client("10.0.0.142", 3030);
	client.Connect();
	client.Send("WHAT");
	return 0;
}