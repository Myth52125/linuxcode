#include <iostream>
#include <vector>
#include <functional>

template <int T>
// 这里定义的参数是一个数组的引用。
// 避免了传入的参数退化成为指针
// 这种方式，传入数组的大小，必须在编译时期确定
int ret_size(int (&i)[T])
{
    std::cout<<T<<std::endl;
    return 0;
}

int main()
{
    int i;
    std::cin>>i;
    // 这里可以使用i确定一个tmp
    // int tmp[i];

    // 数组的大小必须是一个常量，才能够让模板在编译时期确定T的大小
    int tmp[10];    
    std::bind();
    ret_size(tmp);    
}