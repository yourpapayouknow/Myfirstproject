#include<iostream>
using namespace std;
class Vector{
	private:
		int v[100]={0};
	public:
		Vector()
		{	}
		Vector(int a)
		{
			for(int i=0;i<a;i++)
				cin>>v[i];
		}
// 在此处补充你的代码
// 在此处补充你的代码
public:
    // 重载乘法运算符用于计算向量的内积
    int operator*(const Vector& rhs) const {
        int product = 0;
        for (int i = 0; i < 100; i++) {
            product += this->v[i] * rhs.v[i];
        }
        return product;
    }
};

int main()
{
	Vector v1(10),v2(10);
	
	cout<<v1*v2<<endl;
	return 0;
}