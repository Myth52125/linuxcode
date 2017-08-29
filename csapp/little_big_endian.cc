#include <iostream>

int main()
{
	int i=8372;
	unsigned char *pi=reinterpret_cast<unsigned char *>(&i);
	

	for(int j = 0 ;j < sizeof(i);j++)
	{
		std::cout<<(int)pi[j]<<" ";
		
	}

}
