#include "CliSock.h"

int main()
{
	CliSock s(TCP4,0);
	s.goconnect(22);
	return 0;


}
