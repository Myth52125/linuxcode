#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#include <unistd.h>
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
class SerSock
{
public:
	SerSock();
	SerSock(int type,int protocol);
	int startListen(int port,std::string addr);
	int sendMsg(std::string msg);
	std::string readMsg();
private:
	int _getFd();
	int s_family;
	int s_type;
	int s_protocol;
	int s_port;
	std::string s_addr;
	int s_fd;
	
	struct sockaddr_in s_cli;
	struct sockaddr_in s_ser;

	bool is_binded=false;
};
