#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    {
        int temp=0;
        cin>>temp;
        a[i]=temp;
    }
    sort(a,a+n);
    if(a[n-1]==1)
    {
        cout<<"HARD";
    }
    else{
        cout<<"EASY";
    }
    return 0;
}