#include <pthread.h>
#include <iostream>
#include <unistd.h>

int i_ = 0;

pthread_key_t tidKey;

void showAddrUnS()
{

	int i_(1);

	std::cout << "i addr unsafe: " << &i_ << std::endl;
	sleep(10);
}

void showAddrS()
{

	int i_(1);
	pthread_setspecific(tidKey, (void *)i_);
	std::cout << "i addr safe: " << &i_ << std::endl;
	sleep(10);
}

void *thread02(void *)
{
	showAddrS();
}

void *thread01(void *)
{
	showAddrUnS();
}

void des(void *)
{
	std::cout << "call for clean" << std::endl;
}

int main()
{

	int result = pthread_key_create(&tidKey, NULL);
	pthread_t tid01, tid02, tid03, tid04;

	pthread_create(&tid01, NULL, thread01, NULL);
	pthread_create(&tid03, NULL, thread01, NULL);

	pthread_create(&tid02, NULL, thread01, NULL);

	pthread_create(&tid04, NULL, thread01, NULL);
	sleep(1);
	pthread_join(tid04, NULL);











void LogFile::append_unlocked(const char* logline, int len)
{
  _file->append(logline, len);							//添加日志信息

  if (_file->writtenBytes() > _rollSize)				//如果达到日志文件最大大小，那么创建新日志
  {
    rollFile();
  }
  else
  {
    ++_count;
    if (_count >= _checkEveryN)							//达到日志文件的最大记录条数，创建新日志
    {
      _count = 0;
      time_t now = ::time(NULL);
      time_t _thisPeriod = now / kRollPerSeconds_ * kRollPerSeconds_;
      if (_thisPeriod != _startOfPeriod)
      {
        rollFile();
      }
      else if (now - _lastFlush > _flushInterval)
      {
        _lastFlush = now;
        _file->flush();
      }
    }
  }
}

