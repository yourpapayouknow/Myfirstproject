#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	
	string input;
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int count = 0;
		cin>>input;
		string sorted(input);
		sort(sorted.begin(), sorted.end());
		for (int j = 0; j < 3; j++)
		{
			if (input[j] == sorted[j])
			{
				count++;
			}
		}
		if (count == 1 || count == 3)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
