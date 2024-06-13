#include<iostream>
using namespace std;

class array {
public:
    double m_x, m_y, m_z;
    array(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

    // 重载加法运算符
    array operator+(const array& rhs) {
        return array(this->m_x + rhs.m_x, this->m_y + rhs.m_y, this->m_z + rhs.m_z);
    }

    // 重载减法运算符
    array operator-(const array& rhs) {
        return array(this->m_x - rhs.m_x, this->m_y - rhs.m_y, this->m_z - rhs.m_z);
    }

    // 重载内积运算符
    double operator*(const array& rhs) {
        return this->m_x * rhs.m_x + this->m_y * rhs.m_y + this->m_z * rhs.m_z;
    }
};

// 打印函数
void print(array A) {
    cout << A.m_x << ' ' << A.m_y << ' ' << A.m_z << endl;
}

int main() {
    double A1_x, A1_y, A1_z, A2_x, A2_y, A2_z;
    cin >> A1_x >> A1_y >> A1_z >> A2_x >> A2_y >> A2_z;
    array A1(A1_x, A1_y, A1_z), A2(A2_x, A2_y, A2_z);
    print(A1 + A2);
    print(A1 - A2);
    cout << A1 * A2;
    return 0;
}
