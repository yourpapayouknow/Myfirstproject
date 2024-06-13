#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
float ispositive(float x)
{
	if (x > 0)
		return x;
	else
		return -x;
}
int main()
{
	float x[3] = { 0 };
	float y[3] = { 0 };
	scanf("%f %f %f", &x[0], &x[1], &x[2]);
	sort(x, x + 3);
	for (int i = 0; i < 3; i++)
	{
		int a, b, c;
		a=ispositive(x[0]-x[i]);b=ispositive(x[1]-x[i]);c=ispositive(x[2]-x[i]);
		y[i] = a + b + c;
	}
	sort(y, y + 3);
	cout<< y[0];

}
