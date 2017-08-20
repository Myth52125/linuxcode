#include <sys/eventfd.h>
#include <iostream>
#include <unistd.h>
int main()
{
	int efd=eventfd(10,0);
	std::cout<<"eventfd result: "<<efd<<std::endl;
	int ret=fork();
	int result;
	if(ret == 0)
	{
		uint64_t  i=20;
		result=write(efd,&i,sizeof(i));
		std::cout<<"child write: "<<result<<std::endl;
	}else{
		sleep(1);
		uint64_t  i;
		result = read(efd,&i,sizeof(i));
		std::cout<<"parent result: "<<result<<" "<<i<<std::endl;
	
		result = read(efd,&i,sizeof(i));
		std::cout<<"parent result: "<<result<<" "<<i<<std::endl;
	}
}
