#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

pthread_once_t once=PTHREAD_ONCE_INIT;
void thread_init()
{
    printf("thread init \n");
}



void *func01(void *)
{
    thread_init();

}

void *func02(void *)
{
    pthread_once(&once,thread_init);
}

int main()
{
    pthread_t pids01[10];
    pthread_t pids02[10];
    
    for(int i;i<10;i++)
    {
        pthread_create(&pids01[i],NULL,func01,NULL);
    }
    pthread_join(pids01[9],NULL);
    
    sleep(2);
    printf("\n\nusing once :\n\n\n\n");
    
    for(int i;i<10;i++)
    {
        int result = pthread_create(&pids02[i],NULL,func02,NULL);
    }
    pthread_join(pids02[9],NULL);
}