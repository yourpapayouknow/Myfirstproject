#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
    // 在此处补充你的代码
    int* data;
    int row, col;
public:
    // 构造函数
    Array2(int r = 0, int c = 0): row(r), col(c) {
        if(row * col)
            data = new int[row * col];
        else
            data = NULL;
    }

    // 重载括号运算符
    int& operator()(int r, int c) {
        return data[r * col + c];
    }

    // 重载赋值运算符
    Array2& operator=(const Array2& other) {
        if(this != &other) {
            if(data) {
                delete[] data;
            }
            if(other.data) {
                data = new int[other.row * other.col];
                memcpy(data, other.data, sizeof(int) * other.row * other.col);
            } else {
                data = NULL;
            }
            row = other.row;
            col = other.col;
        }
        return *this;
    }

    // 析构函数
    ~Array2() {
        if(data) delete[] data;
    }

    // 重载[]运算符
    class Proxy {
        int* _array;
    public:
        Proxy(int* array): _array(array) {}

        int& operator[](int index) {
            return _array[index];
        }
    };

    Proxy operator[](int r) {
        return Proxy(data + r * col);
    }
};

int main() {
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b; b = a;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}