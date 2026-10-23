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

//int DigitFrequency(int Number, int Digit)
int CountDigitFrequency(int Number, short DigitToCheck)
{
	int Remainder, Counter = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;

		if (Remainder == DigitToCheck)
			Counter++;
	}

	return Counter;
}

int main()
{
	int Number = ReadPositiveNumber("Please enter a number");
	short DigitToCheck = ReadPositiveNumber("Please enter the digit to find its frequency");
	//int Digit = ReadPositiveNumber("Please enter the digit to find its frequency");

	cout << "\nDigit " << DigitToCheck << " Frequency is " << CountDigitFrequency(Number, DigitToCheck);
	cout << " Time(s)" << endl;

	return 0;
}