#include <sys/timerfd.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
int main()
{	
	int fd=timerfd_create(CLOCK_MONOTONIC,0);
	std::cout<<"create timerfd : "<<fd<<std::endl;
	struct itimerspec tm;
	
	time_t ti=time(NULL);
	std::cout<<"time : "<<ti<<std::endl;
	
	bzero(&tm,sizeof(tm));
	tm.it_value.tv_sec=5000+(int)ti;
	tm.it_value.tv_nsec=0;
	
	int setR=timerfd_settime(fd,TFD_TIMER_ABSTIME,&tm,NULL);
	std::cout<<"set timerfd : "<<setR<<std::endl;

	uint64_t i;
	int readR;
//	readR=read(fd,&i,sizeof(i));	
//	std::cout<<"read timerfd : "<<readR<<std::endl;

	
//	sleep(10);
//	readR=read(fd,&i,sizeof(i));	
//	std::cout<<"read timerfd : "<<readR<<std::endl;
	
	struct itimerspec gettime;
	bzero(&gettime,sizeof(gettime));
	int getR=timerfd_gettime(fd,&gettime);
	std::cout<<"getR : "<<getR<<std::endl;
	std::cout<<"get timerfd : "<<gettime.it_value.tv_sec<<std::endl;
	
	
	
}
