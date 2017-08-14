#ifndef _M_THREAD_
#define _M_THREAD_


#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <pthread.h>

namespace myth52125
{
class Thread
{
private:

    typedef boost::function<void ()> ThreadFunc;
    

    pthread_t        _pthread;
    ThreadFunc       _func;
    // std::string      _name;
    bool             _started;
    bool             _joined;

public:
    explicit Thread(const ThreadFunc &func);
    ~Thread();

    void start();
    int join();
};


}

#endif