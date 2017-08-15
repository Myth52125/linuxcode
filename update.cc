#include <unistd.h>
#include <stdlib.h>
int main()
{
	system("cd ~/code");

	
	system("git add *.h *.cc");
	system("git commit -m 'new' ");

	system("git push");
	system("git pull");
	return 0;
}
