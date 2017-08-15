#ifndef _M_EVERYTHREAD_
#define _M_EVERYTHREAD_

#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

namespace myth52125
{
namespace base
{
// __thread pid_t _threadTid(0);
//__thread std::string _threadName("");


inline pid_t tid()
{
	return static_cast<pid_t>(syscall(SYS_gettid));	 
}







}

}
#endif