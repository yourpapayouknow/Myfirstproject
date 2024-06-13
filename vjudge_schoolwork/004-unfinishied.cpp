#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int q; int n, t;
	
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d", &n, &t);
		int* tim = new int[n];
		//int* sortedtim = new int[n];
		int* value = new int[n];
		int*sortedvalue = new int[n];
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &tim[j]);
		}
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &value[j]);
            sortedvalue[j]=value[j];
		}
		//sort(sortedvalue, sortedvalue + n);
		//sort(sortedtim, sortedtim + n);
		if (tim[0] > t)
		{
			printf("-1\n");
		}
		else
		{
			int index = 0;
			/*for (int i = 0; i < n - 1; i++)
			{
				t--;
				if (value[i] < value[i + 1])
				{	
					if (tim[i + 1] <= t&&value[i]<value[i+1])
					{
						index++;
					}

				}
				
			}*/
			for (int i = 0; i <n-1; i++)
			{
                
				if (tim[i] <= t)
				{
					
					index++;
				}
				else
				{
					break;
				}
                t--;
			} 
			if(index>1)
			{ 
                sort(sortedvalue,sortedvalue+index-1);
                if (sortedvalue[index-2]>=value[index-1])
                {
                    for (int j = index - 1; j >0 ; j--)
				    {
						    index--;
                            if(value[j]==sortedvalue[index-2])
                            {
                                break;
                            }
				    }
                }
                
				printf("%d\n", index);
			}
            else if(index==1)
            {
                printf("%d\n", index);
            }
			
		}
		delete[] tim;
		delete[] value;
		delete[] sortedvalue;
		//delete[] sortedtim;
	}
	
	return 0;
}
