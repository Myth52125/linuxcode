#include "SerSock.h"

SerSock::SerSock(int type ,int protocol)
{
	switch (type)
	{
	case TCP4:
		s_family=AF_INET;
		s_type=SOCK_STREAM;
		s_protocol=0;
	}
}

int SerSock::_getFd()
{
	int fd=socket(s_family,s_type,s_protocol);
	std::cout<<"creat server socket fd result: "<<strerror(errno)<<std::endl;
	s_fd=fd;
	return fd;
} 		

int SerSock::startListen(int port,std::string addr)
{
	_getFd();
	s_port=port;
	s_addr=addr;
	bzero(&s_ser,sizeof(s_ser));
	s_ser.sin_family=s_family;
	s_ser.sin_port=htons(s_port);
	int tmpResult;
	tmpResult=inet_pton(s_family,s_addr.c_str(),&s_ser.sin_addr);
	std::cout<<"inet_pton result:"<<strerror(errno)<<std::endl;
	
	
	tmpResult=bind(s_fd,(sockaddr *)&s_ser,sizeof(s_ser));
	std::cout<<"bind result: "<<strerror(errno)<<std::endl;
	if(tmpResult==0)
	{
		is_binded=true;
		int tmp=listen(s_fd,30);
		std::cout<<"listen result: "<<strerror(errno)<<std::endl;
	}	
	

}
