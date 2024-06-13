#include<iostream>
using namespace std;
class Calculator {
	// 在此处补充你的代码
	public:
	float a, b;
	float add();
	float sub();
	float mul();
	float div();
	Calculator(float one, float two)
	{
		a = one; b = two;
	}
};
float Calculator::add()
{
	return a + b;
}
float Calculator::sub()
{
	return a - b;
}
float Calculator::mul()
{
	return a * b;
}
float Calculator::div()
{
	if (b != 0)
	{
		return a / b;
	}
}
void print(Calculator& c)
{
	if(c.b!=0)
		cout << c.add() << " " << c.sub() << " " << c.mul() << " " << c.div() << endl;
	else
	cout << c.add() << " " << c.sub() << " " << c.mul() << endl;
}
int main()
{
	float a, b;
	cin >> a >> b;
	Calculator c(a, b);
	print(c);
	return 0;
}