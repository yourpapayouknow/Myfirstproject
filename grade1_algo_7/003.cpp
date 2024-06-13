#include <iostream>
#include <cmath>
#include<string>
using namespace std;
int main()
{
    long long n,count;
    cin>>n;
    string a=to_string(n);
    for(char c:a)
    {
        if(c=='4'||c=='7')
        {
            count++;
        }
    }
    string b=to_string(count);
    int flag=1;
    for(char c:b)
    {
        if(c!='4'&&c!='7')
            flag=0;
    }
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}