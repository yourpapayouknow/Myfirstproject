#include<iostream>
using namespace std;
class Array {
private:
    int n; // 元素数量
    double* elements; // 实数数组

public:
    // 带参构造函数
    Array(int size, double* data) : n(size), elements(new double[n]) {
        for (int i = 0; i < n; ++i) {
            elements[i] = data[i];
        }
    }

    // 拷贝构造函数
    Array(const Array& other) : n(other.n), elements(new double[n]) {
        for (int i = 0; i < n; ++i) {
            elements[i] = other.elements[i];
        }
    }

    // 赋值运算符重载
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] elements;
            n = other.n;
            elements = new double[n];
            for (int i = 0; i < n; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    // 析构函数
    ~Array() {
        delete[] elements;
    }

    // 前置++
    Array& operator++() {
        for (int i = 0; i < n; ++i) {
            ++elements[i];
        }
        return *this;
    }

    // 后置++
    Array operator++(int) {
        Array temp(*this);
        for (int i = 0; i < n; ++i) {
            elements[i]++;
        }
        return temp;
    }

    // 前置--
    Array& operator--() {
        for (int i = 0; i < n; ++i) {
            --elements[i];
        }
        return *this;
    }

    // 后置--
    Array operator--(int) {
        Array temp(*this);
        for (int i = 0; i < n; ++i) {
            elements[i]--;
        }
        return temp;
    }

    // 显示函数
    void show() const {
        for (int i = 0; i < n; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};
int main() {
	int n;
	double* P;
	cin >> n;
	P = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> P[i];
	}
	Array A(n, P);
	(A++).show();
	(++A).show();
	(--A).show();
	(A--).show();

}