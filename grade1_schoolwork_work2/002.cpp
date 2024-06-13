#include<iostream>
using namespace std;
#define pi 3.14
class Circle {
	// 在此处补充你的代码
public:
	float radius;
	void Set(float r) { radius = r; };
	Circle(float a)
	{
		radius = a;
	}
	double Periment() {
		return pi * 2 * radius;
	};
	double Area() {
		return pi * radius * radius;
	};
};


int main()
{
	float r;
	cin >> r;
	Circle c(r);
	cout << c.Periment() << " " << c.Area() << endl;
	cin >> r;
	c.Set(r);
	cout << c.Periment() << " " << c.Area() << endl;
	return 0;
}