#include <iostream>
#include <string>
using namespace std;

int interleave(string &a, string &b);

int main()
{
    string a;
    string b;
    int ret;
    
    cin>>a>>b;
    ret=interleave(a,b); 
	 
cout<<a<<endl<<ret<<endl;
}
// 在此处补充你的代码
int interleave(string &a, string &b)
{
    int la,lb;
    la=a.length();lb=b.length();
    string c;
    if(la>=lb)
    {
        for(int i=0;i<lb;i=2*i)
        {
            c[i]=a[i];
        }
        for(int i=1;i<lb;i=2*i-1)
        {
            c[i]=b[i-1];
        }
        a=c;
        return (la-lb);
    }
    else
    {
        for(int i=0;i<la;i=2*i)
        {
            c[i]=a[i];
        }
        for(int i=1;i<la;i=2*i-1)
        {
            c[i]=b[i-1];
        }
        a=c;
        return (la-lb);
    }
}