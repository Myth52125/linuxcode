#include <pthread.h>
#include <iostream>
int main()
{
	pthread_mutex_t mutex;
	int result;
	
	result=pthread_mutex_init(&mutex,NULL);
	std::cout<<"init : "<<result<<std::endl;


	result=pthread_mutex_lock(&mutex);
	std::cout<<"look : "<<result<<std::endl;
	
	result=pthread_mutex_lock(&mutex);
	std::cout<<"look : "<<result<<std::endl;

	result=pthread_mutex_unlock(&mutex);
	std::cout<<"unlock : "<<result<<std::endl;

	result=pthread_mutex_unlock(&mutex);
	std::cout<<"unlock : "<<result<<std::endl;
	
	result=pthread_mutex_lock(&mutex);
	std::cout<<"look : "<<result<<std::endl;
	return 0;
}
