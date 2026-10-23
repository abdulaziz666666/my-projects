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

bool IsPerfectNumber(int Num)
{
	int SumOfDivisibles = 0;

	for (int i = 1; i <= Num/2; i++)
	{
		if (Num % i == 0)
			SumOfDivisibles += i;
	}

	return SumOfDivisibles == Num;
}

void PrintPerfectNumberFrom1ToN(int Num)
{
	cout << endl;

	for (int i = 1; i <= Num; i++)
		if (IsPerfectNumber(i))
			cout << i << endl;
}

int main()
{
	int Num = ReadPositiveNumber("Please enter a number");
	PrintPerfectNumberFrom1ToN(Num);
	return 0;
}