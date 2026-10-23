#include <iostream>
using namespace std;

bool ValidateNumberInRange(int Number, int From, int To)
{
	return (Number >= From && Number <= To);
}

int ReadAge()
{
	int Age;

	cout << "Please enter age between 18 and 45: ";
	cin >> Age;

	return Age;
}

//int ReadAgeUntilValid()
int ReadUntilAgeBetween(int From, int To)
{
	int Age;

	do
	{
		Age = ReadAge();

	} while (!ValidateNumberInRange(Age, From, To));

	return Age;
}

void PrintResult(int Age)
{
	cout << endl << Age << " is a valid age" << endl;
}

int main()
{
	PrintResult(ReadAgeUntilValid(18, 45));
	return 0;
}