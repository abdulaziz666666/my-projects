#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Num;

	do
	{
		cout << Message << " (Should be positive): ";
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

void PrintNumberPattern(int Number)
{
	cout << endl;

	for (int i = 1; i <= Number; i++)
	{
		for (int j = 1; j <= i; j++)
			cout << i;

		cout << endl;
	}
}

int main()
{
	int Num = ReadPositiveNumber("Please enter a number");

	PrintNumberPattern(Num);

	return 0;
}