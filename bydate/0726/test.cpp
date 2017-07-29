#include "CliSock.h"
#include "SerSock.h"
int main()
{
	SerSock ser(TCP4,0);
	ser.startListen(22222,"0.0.0.0");
	
	CliSock cli(TCP4,0);
	cli.goconnect(22222);
	return 0;


}
