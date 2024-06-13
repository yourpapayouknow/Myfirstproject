#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
// 在此处补充你的代码
	  // 拷贝构造函数
    MyString(const MyString& another) {
        if (another.p) {
            p = new char[strlen(another.p) + 1];
            strcpy(p, another.p);
        } else {
            p = NULL;
        }
    }

    // 赋值运算符重载
    MyString& operator=(const MyString& another) {
        if (this != &another) {
            if (p) delete[] p;
            if (another.p) {
                p = new char[strlen(another.p) + 1];
                strcpy(p, another.p);
            } else {
                p = NULL;
            }
        }
        return *this;
    }

    // 赋值运算符重载针对常量字符指针
    MyString& operator=(const char * s) {
        if (p) delete[] p;
        if (s) {
            p = new char[strlen(s) + 1];
            strcpy(p, s);
        } else {
            p = NULL;
        }
        return *this;
    }

    // Copy成员函数
    void Copy(const char* s) {
        if (p) delete[] p;
        if (s) {
            p = new char[strlen(s) + 1];
            strcpy(p, s);
        } else {
            p = NULL;
        }
    }

    // 析构函数
    

    // << 运算符重载，用于输出
    friend ostream& operator<<(ostream& out, const MyString& str) {
        if (str.p) {
            out << str.p;
        }
        return out;
    }
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}