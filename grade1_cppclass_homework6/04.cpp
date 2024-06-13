#include<iostream>
using namespace std;
class Matrix{
	private:
		int M[4][4];
	public:
		Matrix()
		{int i,j;
			for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					M[i][j]=0;	}
		Matrix(int a,int b)
		{
			int i,j;
			for(i=0;i<a;i++)
				for(j=0;j<b;j++)
					cin>>M[i][j];
		}
// 加法运算符重载
    Matrix operator+(const Matrix& rhs) const {
        Matrix result;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                result.M[i][j] = M[i][j] + rhs.M[i][j];
        return result;
    }

    // 减法运算符重载
    Matrix operator-(const Matrix& rhs) const {
        Matrix result;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                result.M[i][j] = M[i][j] - rhs.M[i][j];
        return result;
    }

    // 打印矩阵
    friend void Print(const Matrix& mat) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                cout << mat.M[i][j] << " ";
            }
            cout << endl;
        }
    }
}; 
int main()
{
	Matrix x1(2,3),x2(2,3),x3;
	x3 = x1+x2;
	Print(x3);
	x3 = x1-x2;
	Print(x3);
	return 0;	
}