#include <stdio.h>
#include <iostream>

int main()
{
    FILE *fp = fopen("1232", "a");
    std::cout << "fp :" << fp << std::endl;
}

