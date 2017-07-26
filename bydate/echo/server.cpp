#include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
using namespace std;

int main(int argc ,char *argv[])
{
	int fds=socket(AF_INET,SOCK_STREAM,0);
	cout<<"fds: "<<fds<<endl;

	struct sockaddr_in sersock;
	bzero(&sersock,sizeof(sersock));

	sersock.sin_family=AF_INET;
	sersock.sin_port=htons(22222);
	int result = inet_pton(AF_INET,"0.0.0.0",&sersock.sin_addr);
	cout<<"inet_pton: "<<result<<endl;
	
	result=bind(fds,(sockaddr *)&sersock,sizeof(sersock));
	cout<<"bind: "<<result<<endl;
	if(result<0)
	{
		cout<<"bind: "<<strerror(errno)<<endl;
	}
	result=listen(fds,30);
	cout<<"listen: "<<result<<endl;
	
	struct sockaddr_in recsock;
	socklen_t len=sizeof(recsock);	
	for(;;)
	{
		int fdr=accept(fds,(sockaddr *)&recsock,&len);
		pid_t pid=fork();
		if(pid==0)
		{
		cout<<endl<<"pid: "<<getpid()<<endl;
		char buf[1];
		int readLen;
		while(true)
		{
		readLen=read(fdr,buf,1);
		if(readLen>0)
		{
			write(STDOUT_FILENO,buf,1);
		}
		}
		}
	
}
	return 0;

}
