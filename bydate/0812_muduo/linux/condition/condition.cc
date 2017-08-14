#include <iostream>
#include <pthread.h>
#include <vector>


std::vector<int> intV;
pthread_mutex_t mutex;
pthread_cond_t con;

void *readtid(void* arg)
{
	std::cout<<"start read"<<std::endl;
	while(1)
	{
		pthread_mutex_lock(&mutex);
//		std::cout<<"vector size() : "<<intV.size()<<std::endl;
		if(!intV.size())
		{
			std::cout<<"not ready"<<std::endl;
			pthread_cond_wait(&con,&mutex);
		}else{
			std::cout<<"ready"<<std::endl;
			intV.pop_back();
		}
		pthread_mutex_unlock(&mutex);
	}
}

void *change(void *arg)
{
	for(int c=1;c<400;c++)
	{
		pthread_mutex_lock(&mutex);
		if(c%100==0)
		{
			intV.push_back(1);
			pthread_cond_signal(&con);

		}
		
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_t tid1,tid2;
	

	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&con,NULL);

	pthread_create(&tid1,NULL,readtid,NULL);
	pthread_create(&tid1,NULL,change,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;

}
