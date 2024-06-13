#include<iostream>
#include<math.h>
using namespace std;
class Point{
// 在此处补充你的代码
    private:
        double x,y;
    public:
        Point(double x,double y):x(x),y(y){}
        
        double operator-(Point & a)
        {
            return sqrt(x*x+y*y)-sqrt((a.x)*(a.x)+(a.y)*(a.y));
        }
        
};
int main()
{
	double a,b,c,d,len;
	cin>>a>>b>>c>>d;
	Point p1(a,b),p2(c,d);
	len = p1-p2;
	if(len<0) len = -len;
	cout<<len<<endl;
	return 0;
}