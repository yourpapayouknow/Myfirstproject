#include<iostream>
using namespace std;
struct Date
{
    public:
    int year,month,day;
    void setDate();
    bool IsLeapYear();
    
    /* data */
};
bool IsLeapYear(Date & q)
{
    return (q.year%4==0&&q.year%100!=0)||(q.year%400==0);
}
void setDate(Date * p)
    {
        int y,m,d;
        cin>>y>>m>>d;
        p->year=y;p->month=m;(*p).day=d;
    }
// 在此处补充你的代码
int main()
{
	Date d;
	setDate(&d);
	cout<<IsLeapYear(d);
	return 0;
}