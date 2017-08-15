#include <Thread.h>
#include <iostream>
#include <EveryThread.h>
#include <ThreadPool.h>

void pthread1()
{
    std::cout<<"thread 1 : run"<<std::endl;
}


int main()
{
    using namespace myth52125;

    Thread thread01(pthread1);
    thread01.start();
    thread01.join();

    std::cout<<"thread pool test :start:"<<std::endl;

    ThreadPool pool(10);
    pool.start(3);

    for(int i=0;i<=100;i++)
    {
        std::cout<<"add"<<std::endl;
     
        pool.add(pthread1);    
    }
    int i;
    while (std::cin>>i)
    {
        if(i==0)
        {
            pool.add(pthread1);    
        
        }
    }
    return 0;
}