#include <stdio.h>

extern int  global;
int main()
{
    global++;
    printf("sizeof global: %d \n",sizeof(global));
}