#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
void *func(void *)
{
	while(true)
{
	printf("thread run \n");
	sleep(1);
}
}

int main()
{
	pthread_attr_t attr;
	int result;
	result = pthread_attr_init(&attr);
	printf("attr init reslut :%d \n",result);
	int i;	
	result =pthread_attr_getdetachstate(&attr,&i);
	printf("get reslut :%d, %d \n",result,i);

	pthread_t pid;
	pthread_create(&pid,&attr,func,NULL);
	printf("create pthread reslut :%d \n",result);
	
	result = pthread_attr_destroy(&attr);
	printf("destroy reslut :%d \n",result);
	sleep(12);
}
