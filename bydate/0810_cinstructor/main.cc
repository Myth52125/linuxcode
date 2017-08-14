#include "A.h"

int main()
{
	int i=4444;
	A a(i);
	A b=a;
	std::cout<<b.ri<<std::endl;
	std::cout<<a.ri<<std::endl;
	i=2;
	std::cout<<b.ri<<std::endl;
	std::cout<<a.ri<<std::endl;
	return 0;
}
