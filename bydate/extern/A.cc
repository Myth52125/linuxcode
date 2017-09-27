#include "A.h"

int __thread i = 1;
int a()
{
	return i;
}