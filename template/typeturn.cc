
//对引用类型传数组,数组会转指针，然后又转化为对指针的引用
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
int add1(T &v)
{
    cout<<*v<<endl;
    *v=4;
    return 1;
}

template <typename T,typename V>
int add2(T &t,V &v)
{
    return 1;
}

template <typename T,typename V>
auto add3(T &t,V &v) -> decltype(1)
{
    return 1;
}

template <typename T>
void add4(T &&i)
{

}

int main()
{
    int *p=new int(1);
    int pz[10]={2,3};

    add1(p);
    add1(pz);
    add1(p);
    add1(pz);
    int i=1;
    long ii=2;
    int iii=i+ii;
    // add1(i,ii);
    ofstream ff("output11");


    add2(cout,ff);

     i=1;
    add4(i);
    add4(12);

}