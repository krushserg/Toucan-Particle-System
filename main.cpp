#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;


int prnt(function<int()> f)
{
    return f();
}

int main()
{
    vector<int> v = {10,11,12,13,14,15};
    for_each(v.begin(),v.end(),[](int& a){a = -a;});

    for(int a:v)
        cout<<a<<endl;
    return 0;
}

