#include <pthread.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <iostream>
#include <sys/prctl.h> 

struct arg
{
	int i;
	char c;
};

__thread int tmp=1;

void *printTid1(void *i)
{
//	std::cout<<"pthread gettid():"<<gettid()<<std::endl;
	std::cout<<"syscall tid:"<<syscall(SYS_gettid)<<std::endl;

	//prctl()

	char buf[521];
	prctl(PR_GET_NAME,buf);
	
   	const char *bufname="own name";
	std::cout<<"thread prctl name : "<<buf<<std::endl;
	prctl(PR_SET_NAME,bufname);
	
	prctl(PR_GET_NAME,buf);
	std::cout<<"thread prctl name : "<<buf<<std::endl;

	struct arg* arg1;
	arg1=(struct arg*)i;
	std::cout<<arg1->c<<std::endl;
	
	tmp++;
	std::cout<<"tmp in thread 1: "<<tmp<<std::endl;
}

void *printTid2(void *i)
{
//	std::cout<<"pthread gettid():"<<gettid()<<std::endl;
	std::cout<<"syscall tid:"<<syscall(SYS_gettid)<<std::endl;


	struct arg* arg1;
	arg1=(struct arg*)i;
	std::cout<<arg1->c<<std::endl;
	
	tmp--;
	std::cout<<"tmp in thread 2: "<<tmp<<std::endl;
}



int main()
{
	struct arg arg1;
	arg1.i=1;
	arg1.c='u';


	pthread_t newT1;	
	pthread_t newT2;	
	pthread_create(&newT1,NULL,printTid1,&arg1);

	sleep(2);
//	std::cout<<"main thread: "<<syscall(SYS_gettid)<<std::endl;
//	std::cout<<"main pid: "<<getpid()<<std::endl;
//	std::cout<<"tmp: "<<tmp<<std::endl;
	return 0;

}
