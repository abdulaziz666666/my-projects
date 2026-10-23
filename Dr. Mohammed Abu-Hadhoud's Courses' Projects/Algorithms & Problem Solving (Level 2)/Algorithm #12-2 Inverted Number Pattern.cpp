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

void PrintInvertedNumberPattern(int Num)
{
	cout << endl;

	for (int Counter = Num; Counter >= 1; Counter--)
	{
		for (int i = 1; i <= Counter; i++)
			cout << Counter;

		cout << endl;
	}
}

int main()
{
	int Num = ReadPositiveNumber("Please enter a number");

	PrintInvertedNumberPattern(Num);

	return 0;
}