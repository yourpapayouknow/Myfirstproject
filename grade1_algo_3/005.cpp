#include <cstdio>
#include <iostream>
using namespace std;
int r[500002];
bool flag[3500005]={0};
int main()
{
    r[0]=0;
    int temp;
    for(int i=1;i<500000;i++)
    {
        temp=r[i-1]-i;
        if(temp>0&&flag[temp]==0)
        {
            r[i]=temp;
        }
        else
        {
            r[i]=r[i-1]+i;
        }
        flag[r[i]]=1;
    }
    int k;
    while(scanf("%d",&k)&&k!=-1)
    {
        printf("%d\n",r[k]);
    }
    return 0;
}