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

int ReverseNumber(int Number)
{
	int Remainder, ReversedNumber = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		ReversedNumber = ReversedNumber * 10 + Remainder;
	}

	return ReversedNumber;
}

//bool IsPalindrome(int Number)
bool IsPalindromeNumber(int Number)
{
	return Number == ReverseNumber(Number);
}

int main()
{
	int Number = ReadPositiveNumber("Please enter a number");

	// i had better put the code below in a separate procedure.
	cout << endl;

	if (IsPalindromeNumber(Number))
		cout << "Yes, it is a Palindrom Number\n";
	else
		cout << "No, it is NOT a Palindrom Number\n";

	return 0;
}