#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int index[103];
    for(int i=1;i<=n;i++)
    {
        cin>>index[i];
    }
    int result[103];
    for(int i=1;i<=n;i++)
    {
        result[index[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<result[i];
        if(i!=n)
            cout<<" ";
    }


    
}