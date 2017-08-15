#ifndef _M_THREADPOOL_
#define _M_THREADPOOL_


#include <iostream>
#include <Thread.h>
#include <pthread.h>
#include <Mutex.h>
#include <deque>
#include <Condition.h>
#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

namespace myth52125
{

class ThreadPool
{
public:
	typedef boost::function<void ()> Task;
private:
    Condition _doTask;
    Condition _addTask;
    
    size_t _maxQueueSize;
    std::deque<Task> _queue;
    MutexLock _mutex;

    bool _started;

    boost::ptr_vector<Thread>  _threadPool;
        
    Task takeTask();

    void *runInThread();

    bool isFull();

public:

    
    explicit ThreadPool(size_t maxQueueSize);
    ~ThreadPool();

    void start(size_t num);
    void stop();

    void add(Task task);

};




}




#endif
