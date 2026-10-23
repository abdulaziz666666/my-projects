#include <iostream>
#include <cmath>
using namespace std;

enum enNumberType {Prime, NonPrime};

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

enNumberType CheckNumberType(int Num)
{
	// excluding some cases to deal with odd numbers only.
	if (Num <= 1) // 1 or less
		return enNumberType::NonPrime;
	else if (Num == 2) // the only even and prime number
		return enNumberType::Prime;
	else if (Num % 2 == 0) // even but not 2
		return enNumberType::NonPrime;

	// odd numbers left..
	for (int Counter = 3; Counter <= round(Num / 2); Counter += 2)
	{
		if (Num % Counter == 0)
			return enNumberType::NonPrime;
	}

	return enNumberType::Prime;
}

void PrintPrimeNumbersFrom1ToN(int N)
{
	cout << "\nPrime Numbers From 1 To " << N << " Are:\n";

	for (int i = 1; i <= N; i++)
	{
		if (CheckNumberType(i) == enNumberType::Prime)
			cout << i << "\n";
	}

	cout << endl; // to empty the buffer.
}

int main()
{
	int Num = ReadPositiveNumber("Please enter a number");
	PrintPrimeNumbersFrom1ToN(Num);

	return 0;
}