#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TCP4 1

class CliSock
{
public:
	CliSock():s_family(AF_INET,s_type(SOCK_STREAM),s_protocol(0);
	CliSock(int type);


private:
	int s_family;
	int s_type;
	int s_protocol;
	int s_port;
	

}
