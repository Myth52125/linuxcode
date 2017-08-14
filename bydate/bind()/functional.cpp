#include <functional>
#include <string>
#include <iostream>
int saySomething(std::string name,std::string someword)
{
	std::cout<<name+" say :"<<someword<<std::endl;
	return 1;
}
template <typename F>
int watchSomething(std::string name,F f)
{
	std::cout<<name<<" saw: ";
	f();
	std::cout<<std::endl;
}

int main()
{
	saySomething("maya","fuck mather");
	auto fun=std::bind(saySomething,"maya","fuck bind ");
	int i=fun();
	std::cout<<"fun return : "<<i<<std::endl; 
//	watchSomething("xiaoming",std::bind(saySomething,"maya","fuck"));
	watchSomething("xiaoming",fun);
	return 1;
}
