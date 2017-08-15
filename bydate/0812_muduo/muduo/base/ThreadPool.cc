#include <ThreadPool.h>
#include <boost/bind.hpp>

using namespace myth52125;
typedef boost::function<void ()> Task;

ThreadPool::ThreadPool(size_t maxQueueSize):
    _maxQueueSize(maxQueueSize),
    _started(false),
    _doTask(_mutex),_addTask(_mutex)
    {

    }
    
ThreadPool::~ThreadPool()
{
    if(_started)
    {
        stop();
    }
}

Task ThreadPool::takeTask()
{
    MutexLockGuard look(_mutex);

    while(_queue.empty() && _started)
    {
        _doTask.wait();
    }

    Task task;
    

    if(!_queue.empty() && _started)
    {
        task=_queue.front();
        _queue.pop_back();

        if(!isFull())
        {
            _addTask.notifyAll();
        }
    }
    return task;
}

void *ThreadPool::runInThread()
{
    while(_started)
    {
        Task task(takeTask());
        if(task)
        {
            task();
        }    
    }
}

void ThreadPool::add(Task task)
{
    if(_threadPool.empty())
    {
        task();
    }else
    {    

        MutexLockGuard look(_mutex);
    
        while(isFull())
        {
            _addTask.wait();
        }

        _queue.push_back(task);
        _doTask.notify();
    }
}

void ThreadPool::start(size_t num)
{ 
    if(!_started)
    {
        _started=true;
        _threadPool.reserve(num);    ;
        for (int i=0 ;i<=num;i++)
        {
            _threadPool.push_back(
                new Thread(boost::bind(&ThreadPool::runInThread,this))
            );
            _threadPool[i].start();
        }
    }
}

void ThreadPool::stop()
{
    {
        MutexLockGuard look(_mutex);
        _started=false;
        _doTask.notifyAll();
    }

    for_each(
        _threadPool.begin(),_threadPool.end(),
        boost::bind(&Thread::join,_1)
    );
}


bool ThreadPool::isFull()
{    
    return (_queue.size()>=_maxQueueSize);
}