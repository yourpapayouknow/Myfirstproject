#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[100];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<a[0]<<endl;
    }
    return 0;
    
}