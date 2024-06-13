#include <iostream>
#include <cstdio>
using namespace std;
void exchange_value(int  ,int );  //值作参数，函数参数值
void exchange_pointer1(int *,int *);  //指针作参数1，交换指针指向内容
void exchange_pointer2(int *,int *);  //指针作参数2，交换指针
void exchange_reference(int &,int &);  //引用作参数，交换参数值
void exchange(int  ,int );  //值作参数，函数参数值
void exchange(int *,int *);  //指针作参数1，交换指针指向内容
void exchange_avalue(int*,int*,int);  //指针作参数2，交换指针 。第三个传实参0。

int main()
{
    //定义变量
    int a=1,b=2;
    exchange_value(a,b);
//调用函数exchange_value，输出变量a和b的值；

//变量重新赋值
a=1,b=2;
//调用函数exchange_pointer1，输出变量a和b的值；
exchange_pointer1(&a,&b);
//变量重新赋值
a=1,b=2;
//调用函数exchange_pointer2，输出变量a和b的值；
    //int* ptr1 = &a;
    //int* ptr2 = &b;
exchange_pointer2(&a,&b);
//变量重新赋值
a=1,b=2;
//调用函数exchange_reference，输出变量a和b的值；
exchange_reference(a,b);
//变量重新赋值
a=1,b=2;
//调用重载函数void exchange(int  ,int ); 输出变量a和b的值；
exchange(a,b);
//变量重新赋值
a=1,b=2;
exchange(&a,&b); 
//调用重载函数void exchange(int *,int *); 输出变量a和b的值；

//变量重新赋值
 a=1, b=2;
//调用重载函数void exchange(int* ,int* ,int); 输出变量a和b的值；
//int* pt1=&a;int* pt2=&b;
//int c=0;
printf("%s%d%s%s%d\n","a=",a,",","b=",b);

//exchange_avalue(&pt1,&pt2);
}
void exchange_value(int a,int b)
{
    printf("%s%d%s%s%d\n","a=",a,",","b=",b);
}
void exchange_pointer1(int *pa,int *pb)
{
    int temp=0;
    temp=*pa;*pa=*pb;*pb=temp;
    printf("%s%d%s%s%d\n","a=",*pa,",","b=",*pb);
}
void exchange_pointer2(int *pa,int *pb)
{
   // int temp=0;
    //temp=*pa;*pa=*pb;*pb=temp;
    printf("%s%d%s%s%d\n","a=",*pa,",","b=",*pb);
}
void exchange_reference(int &a,int &b)
{
    int temp=0;
    temp=a;a=b;b=temp;
    printf("%s%d%s%s%d\n","a=",a,",","b=",b);
}
void exchange(int a,int b)
{
    printf("%s%d%s%s%d\n","a=",a,",","b=",b);
}
void exchange(int *pa,int *pb)
{
    int temp=0;
    temp=*pa;*pa=*pb;*pb=temp;
    printf("%s%d%s%s%d\n","a=",*pa,",","b=",*pb);
}
////void exchange_avalue(int **a,int **b)
//{//
  //  printf("%s%d%s%s%d\n","a=",a,",","b=",b);
//}