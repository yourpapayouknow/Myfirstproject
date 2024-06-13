#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int pow2[31];
    pow2[30]=1073741824;
    for(int i=0;i<31;i++)
        pow2[i]=pow(2.0,i);
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<31;i++)
            if(n>=pow2[i]&&n<pow2[i+1])
                {
                    cout<<pow2[i]-1<<endl;
                    break;
                }
    }
}