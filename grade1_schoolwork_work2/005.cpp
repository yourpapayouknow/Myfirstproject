#include<iostream>
using namespace std;
class cat
{
	int age;
	public:
		void SetAge(int a);
		int GetAge();
		void Meow();

};
void cat::SetAge(int a)
{
	age = a;
}
int cat::GetAge()
{
	return age;
}
void cat::Meow()
{
	cout << "Meow." << endl;
}
int main()
{
	cat frisky;
	frisky.SetAge(5);
	frisky.Meow();
	cout << "frisky is a cat who is " << frisky.GetAge() << " years old." << endl;
	frisky.Meow();
	return 0;
}
	
