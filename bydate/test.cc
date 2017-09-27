#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k;
    vector<int> v;
    cin>>k;
    v.push_back(k);

    for(auto i :v)
    {
        cout<<i<<" ";
    }
}