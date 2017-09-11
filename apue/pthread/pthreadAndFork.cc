#include <pthread.h>
#include <unistd.h>
#include <stdio.h>


pthread_mutex_t mutex;

void *func01(void *)
{
    sleep(10);
    pid_t pid = getpid();
    printf("func01 run in %d \n",pid);
    
}


int main()
{
    pthread_mutex_init(&mutex,NULL);

    pthread_t pids[10];

    // for(int i = 0; i<10;i++)
    // {
    //     pthread_create(&pids[i],NULL,func01,NULL);    
    // }

    pthread_mutex_lock(&mutex);
    

    pid_t pid = fork();
    if(pid)
    {
        printf("\n\n\n parent \n\n\n");
    pthread_mutex_lock(&mutex);
    
    }else
    {
        printf("\n\n\n chrild \n\n\n");
        
    }
    pthread_mutex_unlock(&mutex);
    
    sleep(100);
}