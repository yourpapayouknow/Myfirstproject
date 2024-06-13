#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int * input = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%lld", &input[i]);
	}
	sort(input, input + n);
	int std = n / 2;
	if (n % 2 != 0)
	{
		printf("%d", input[std]);
	}
	else
	{
		
		printf("%d", input[std - 1]);
	}
	delete[] input;
	return 0;
}