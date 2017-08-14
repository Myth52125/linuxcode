#include <Thread.h>

//
namespace myth52125
{
struct ThreadData
{
    typedef boost::function<void ()> ThreadFunc;


    ThreadFunc _func;
    std::string _name;

    ThreadData(ThreadFunc &func)
        :_func(func)
    {

    }

    void runInThread()
    {
        //_threadName=_name.empty()?"no name":_name.c_str();
        // ::prctl(PR_SET_NAME, _threadName);
        _func();
    }
};


//
void *sendedIntoThread(void *data)
{   
    ThreadData *data_=static_cast<ThreadData *>(data);
    data_->runInThread();
    delete data_;
    return NULL;
}

}





using namespace myth52125;    


Thread::Thread(const ThreadFunc &func)
    :_func(func),
    _started(false), _joined(false),
    _pthread(0)
{

}

Thread::~Thread()
{
    if(_started&&!_joined)
    {
        pthread_detach(_pthread);
    }
}

void Thread::start()
{
    _started=true;
    ThreadData *data=new ThreadData(_func);   //so delete
    if(pthread_create(&_pthread,NULL,sendedIntoThread,data))
    {
        _started=false;
        delete data;
    }
}

int Thread::join()
{
    _joined=true;
    return pthread_join(_pthread,NULL);
}



