#include <iostream>
#include <string>
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

int SumOfDigits(int Num)
{
	int Remainder, SumOfDigits = 0;

	while (Num > 0)
	{
		Remainder = Num % 10;
		Num /= 10;
		SumOfDigits += Remainder;
	}

	return SumOfDigits;
}

int main()
{
	int Num = ReadPositiveNumber("Please enter a number");

	cout << "\nSum Of Digits = " << SumOfDigits(Num) << endl;

	return 0;
}