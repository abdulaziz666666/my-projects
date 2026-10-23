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

int CountDigitFrequency(int Number, int Digit)
{
	int Remainder, Counter = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;

		if (Remainder == Digit)
			Counter++;
	}

	return Counter;
}

void PrintAllDigitsFrequency(int Number)
{
	short DigitFrequency;

	for (int i = 0; i <= 9; i++)
	{
		DigitFrequency = CountDigitFrequency(Number, i);

		if (DigitFrequency > 0)
		{
			cout << "\nDigit " << i << " Frequency is "
				 << DigitFrequency << " Time(s)\n";
		}
	}
}

int main()
{
	int Num = ReadPositiveNumber("Please enter a number");
	
	PrintAllDigitsFrequency(Num);

	return 0;
}