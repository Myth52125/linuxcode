#include <iostream>
int main()
{
	int i=1;
	std::cin>>i;
	if(__builtin_expect(i==1,0))
	{
		std::cout<<"is 1"<<std::endl;
	
	}else{	
		std::cout<<"not 1"<<std::endl;
 	}

}
