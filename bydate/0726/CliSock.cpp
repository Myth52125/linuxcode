#include "CliSock.h"

CliSock::CliSock(int type,int sprotocol)
{
	switch (type)
	{
		case TCP4:
			s_family=AF_INET;
			s_type=SOCK_STREAM;
			s_protocol=0;
	}
	std::cout<<"CliSock(int )"<<std::endl;
}

CliSock::CliSock():CliSock(TCP4,0)
{}

int CliSock::_getFd(int family,int type,int protocol)
{
	int fd=socket(family,type,protocol);
	std::cout<<"create socket fd result: "<<strerror(errno)<<std::endl;
	s_fd=fd;
	return fd;

}

int CliSock::goconnect(int port, std::string addr)
{
	s_port=port;
	s_addr=addr;
	int fd=_getFd(s_family,s_type,s_protocol);
	bzero(&s_cli,sizeof(s_cli));
	s_cli.sin_port=htons(s_port);
	s_cli.sin_family=s_family;
		
	int tmpResult=inet_pton(s_family,s_addr.c_str(),&s_cli.sin_addr);
	std::cout<<"inet_pton result : "<<strerror(errno)<<std::endl;
	tmpResult = connect(s_fd,(sockaddr *)&s_cli,sizeof(s_cli));
	std::cout<<"connect result :"<<strerror(errno)<<std::endl;

}
