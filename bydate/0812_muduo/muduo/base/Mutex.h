#ifndef _M_MUTEX_
#define _M_MUTEX_

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <EveryThread.h>

#include <boost/noncopyable.hpp>
namespace myth52125
{

using namespace myth52125;

class MutexLock: boost::noncopyable
{
  private:
	pthread_mutex_t			 _mutex;
	pid_t 				 	 _inWhichThread;

	void assignThread()
	{
		// _inWhichThread = EveryThread::tid();
	}

	void unassignThread()
	{
		_inWhichThread = 0;
	}


	

  public:
	MutexLock()
	{
		int resullt = pthread_mutex_init(&_mutex,NULL);
		
	}

	~MutexLock()
	{
		pthread_mutex_destroy(&_mutex);
	}

	void lock()
	{
		// assignThread();
		pthread_mutex_lock(&_mutex);
	}
	void unlock()
	{
		// unassignThread();
		pthread_mutex_unlock(&_mutex);
	}
	void unassignHolder()
	{

	}
	pthread_mutex_t *getMutex()
	{
		return &_mutex;
	}
};





class MutexLockGuard
{
private:
	MutexLock &_mutex;
public:
	explicit MutexLockGuard(MutexLock &mutex):_mutex(mutex)
	{
		_mutex.lock();
	}

	~MutexLockGuard()
	{
		_mutex.unlock();
	}

};
}

#endif