#include <iostream>


#include <memory.h>

using namespace std;

class A
{
public:
	A()
		:_i(A::i++)
	{
		std::cout<<" A constructor running, Num : "<<_i<<std::endl;
	}

	static int i;
	~A()
	{
	
		std::cout<<" A destry ,Num : "<<_i<<endl;
	}

	int _i;
};

int A::i =0;




int main()
{
	cout<<endl<<"main start"<<endl<<endl;


	A a;

	shared_ptr<A> ap;














cout<<endl<<"user code over. "<<endl<<endl;

}



