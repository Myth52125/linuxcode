#ifndef _M_CONDITION_
#define _M_CONDITION_


#include <iostream>
#include <pthread.h>
#include <Mutex.h>
#include <error.h>

#include <boost/noncopyable.hpp>

namespace myth52125
{
class Condition: boost::noncopyable
{
private:
    MutexLock &_mutex;
    pthread_cond_t _cond;

public:
    explicit Condition(MutexLock &mutex)
        :_mutex(mutex)
    {
        int result =pthread_cond_init(&_cond, NULL);
        
    }

    ~Condition()
    {
        pthread_cond_destroy(&_cond);
    }
    void wait()
    {
        int result = pthread_cond_wait(&_cond,_mutex.getMutex());
        
    }
    void notify()
    {
        pthread_cond_signal(&_cond); 
    }
    void notifyAll()
    {
        pthread_cond_broadcast(&_cond);
    }
};


}





#endif