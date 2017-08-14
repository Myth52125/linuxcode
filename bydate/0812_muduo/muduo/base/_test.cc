#include <Thread.h>
#include <iostream>
#include <EveryThread.h>

void pthread1()
{
    std::cout<<"thread 1 : "<<std::endl;
}


int main()
{
    using namespace myth52125;

    Thread thread01(pthread1);
    thread01.start();
    thread01.join();
}