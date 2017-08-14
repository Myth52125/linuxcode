#include <iostream>

class A
{
public:
	A(int& a):ri(a){
	std::cout<<a<<std::endl;
	}
	int i=222;
 	int &ri;
	~A()
	{
		std::cout<<i;
	}
};
