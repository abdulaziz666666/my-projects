#include <iostream>
using namespace std;

void ReadAge(unsigned short& Age)
{
	cout << "Please enter your age: ";
	cin >> Age;

	cout << endl;
}

void PrintValidaty(unsigned short Age)
{
	if (Age >= 18 && Age <= 45)
	{
		cout << "Valid Age" << endl;
	}
	else
	{
		cout << "Invalid Age" << endl;
	}
}

int main()
{
	unsigned short Age;

	ReadAge(Age);
	PrintValidaty(Age);

	return 0;
}