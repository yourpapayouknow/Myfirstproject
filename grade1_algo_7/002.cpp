#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count = 0;
    while(n--)
    {
        int p,q;
        cin>>p>>q;
        int remain=q-p;
        if(remain>=2)
            count++;
    }
    cout<<count;
}