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
	short Remainder;
	int ReversedNumber = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		ReversedNumber = ReversedNumber * 10 + Remainder;
	}

	return ReversedNumber;
}

void PrintDigitsReversely(int Number)
{
	short Remainder;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		cout << Remainder << endl;
	}
}

// in reality, it starts from the last digit; so it has 
// to reverse the number firstly, then print the "first" digit,
// which became the last now.
void PrintDigitsInOrder(int Number)
{
	// because the user has nothing to do with anything under the table.
	Number = ReverseNumber(Number); 
	PrintDigitsReversely(Number);
}

int main()
{
	int Num = ReadPositiveNumber("Please enter a number");

	// you can use one of them; as they are equivalences.
	PrintDigitsInOrder(Num);
	//PrintDigitsReversely(ReverseNumber(Num));

	// you can also make it in one procedure as an ability
	// to print in order or reversely. it is up to you.

	return 0;
}