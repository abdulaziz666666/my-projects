#include <iostream>
using namespace std;

int ReadIntegerInRange1(int From, int To)
{
	int Num;

	cout << "Please enter a number between " << From << " and " << To << ": \n";
	cin >> Num;

	while (Num < From || Num > To)
	{
		cout << "Wrong number, ";
		cout << "Please enter a number between " << From << " and " << To << ": \n";
		cin >> Num;
	}

	return Num;
}

int ReadIntegerInRange2(int From, int To)
{
	int Num;

	do
	{
		cout << "Please enter a number between " << From << " and " << To << ": \n";
		cin >> Num;

	} while (Num < From || Num > To);

	return Num;
}

int main()
{
	cout << "while loop\n\n";
	ReadIntegerInRange1(1, 10);
	cout << "\n\ndo while loop\n\n";
	ReadIntegerInRange2(1, 10);
	return 0;
}