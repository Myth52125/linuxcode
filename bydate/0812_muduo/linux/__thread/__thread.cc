#include <pthread.h>
#include <iostream>
#include <unistd.h>
__thread int i = 0;
int a=0;
void *thread01(void *)
{
	std::cout<<"i in 01: "<<i<<std::endl;
	std::cout<<"a in 01: "<<a<<std::endl;
	i=2;
	a=2;
	sleep(1);
}


int main()
{
	pthread_t tid01,tid02;
	pthread_create(&tid01,NULL,thread01,NULL);
	pthread_create(&tid02,NULL,thread01,NULL);
	sleep(2);
}
