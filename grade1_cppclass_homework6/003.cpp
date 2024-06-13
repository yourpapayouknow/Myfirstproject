#include<iostream>
using namespace std;
class Complex
{
	private:
		double real,imag;
	public:
public:
    // 构造函数
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 友元函数声明
    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    friend Complex operator+(double a, const Complex& b);

    // 获取实部
    double getReal() const { return real; }
    // 获取虚部
    double getImag() const { return imag; }
};

// 全局打印函数
void print(const Complex& c) {
    if(c.getImag() >= 0)
        cout << c.getReal() << "+" << c.getImag() << "i" << endl;
    else
        cout << c.getReal() << c.getImag() << "i" << endl;
}

// 加法运算符重载
Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

// 减法运算符重载
Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a.real - b.real, a.imag - b.imag);
}

// 实数与复数的加法运算符重载
Complex operator+(double a, const Complex& b) {
    return Complex(a + b.real, b.imag);
};
int main()
{
	double d1,d2,b1,b2;
	cin>>d1>>d2>>b1>>b2;
	Complex c1(d1,d2),c2(b1,b2),c3;
	c3 = c1+c2;
	print(c3);
	c3 = c1-c2;
	print(c3);
	c3 = 3.5+c2;
	print(c3);
	return 0;
}