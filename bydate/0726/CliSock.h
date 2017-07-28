#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef SOCKET
#define SOCKET
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <string>
#include <string.h>
#include <errno.h>
#endif


#define TCP4 1


class CliSock
{
public:
	CliSock(int stype ,int sprotocol);
	CliSock();	
	int goconnect(int port=0,std::string addri="0.0.0.0");
private:
	int _getFd(int family,int type,int protocol);
	int s_family;
	int s_type;
	int s_protocol;
	std::string s_addr;
	int s_port;
	std::string addr;
	
	int s_fd;
	struct sockaddr_in s_cli;
};
