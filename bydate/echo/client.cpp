#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
	int fds = socket(AF_INET,SOCK_STREAM,0);
	if(fds==-1) cout<<"socket err"<<endl;
	cout<<"fds: "<<fds<<endl;

	struct sockaddr_in clisock;
	bzero(&clisock,sizeof(clisock));
	clisock.sin_family=AF_INET;
	clisock.sin_port=htons(22222);
	int result=inet_pton(AF_INET,"127.0.0.1",&clisock.sin_addr);
	cout<<"inet_pton: "<<result<<endl;
	
	result=connect(fds,(sockaddr*)&clisock,sizeof(clisock));
	cout<<"connect: "<<result<<endl;
	if(result<0)
	{
		cout<<"connect: "<<strerror(errno)<<endl;
	}
	char buf;
	while(cin>>buf)
	{
		write(fds,&buf,1);
	}
	return 0;
}
