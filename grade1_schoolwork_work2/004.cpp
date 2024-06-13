#include <iostream>
using namespace std;
class Date
{
	int day, month, year;
	public:
		Date(int d, int m, int y)
		{
			day = d;
			month = m;
			year = y;
		};
		void display()
		{
			cout << day << "/" << month << "/" << year << endl;
		};
		void display1()
		{
			cout << (1 + day) << "/" << month << "/" << year << endl;

		};
		void set(int d, int m, int y)
		{
			day = d;
			month = m;
			year = y;
		};
};
int main()
{
	int d=0, m=0, y=0;
	scanf("%d %d %d", &y, &m, &d);
	Date date(d, m, y);
		date.display();
		date.display1();
	scanf("%d %d %d", &y, &m, &d);
	date.set(d, m, y);
	date.display();
	return 0;

}