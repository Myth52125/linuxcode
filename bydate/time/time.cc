#include <time.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
  

int main()
{


	time_t t=time(&t);
	std::cout<<"time_t t : "<<(int)t<<std::endl;

	struct tm *_tm;
//	_tm=gmtime(&t);
//	std::cout<<"gmtime : _tm.tm_hour :"<<_tm->tm_hour<<std::endl;
	
//	_tm=localtime(&t);
//	std::cout<<"localtime : _tm.tm_hour :"<<_tm->tm_hour<<std::endl;

	std::cout<<"with _r"<<std::endl;

	struct tm tmp_tm;
	localtime_r(&t,&tmp_tm);
	
	std::cout<<"localtime_r : tmp_tm.tm_hour :"<<tmp_tm.tm_hour<<std::endl;
	std::cout<<"localtime_r : _tm.tm_hour :"<<_tm->tm_hour<<std::endl;

	return 0;

}

