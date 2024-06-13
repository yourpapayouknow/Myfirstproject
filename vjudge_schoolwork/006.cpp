#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int n,couponum,couponpri;
	cin >> n;
	long long* price = new long long[n];
	long long cost = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}
	sort(price, price + n);
	long long total = 0;
	for (int i = 0; i < n; i++)
	{
		total += price[i];
	}
	cin >> couponum;
	for (int j = 0; j < couponum; j++)
	{
		cin >> couponpri;
		total=total-price[n-couponpri];
		cout<< total << endl;
		total = total + price[n - couponpri];
	}
	return 0;
}