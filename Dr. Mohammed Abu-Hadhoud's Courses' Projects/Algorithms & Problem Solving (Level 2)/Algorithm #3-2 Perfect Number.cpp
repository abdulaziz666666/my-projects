#include <iostream>
using namespace std;

//enum enPerfectNumberOrNot {Perfect, NotPerfect};

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

	//if (SumOfDivisibles == Num)
	//	return true;
	//else
	//	return false;

	return SumOfDivisibles == Num;
}

void PrintPerfectOrNot(int Num)
{
	cout << endl;

	if (IsPerfectNumber(Num))
		cout << Num << " is Perfect!\n";
	else
		cout << Num << " is NOT Perfect!\n";
}

int main()
{
	int Num = ReadPositiveNumber("Please enter a number to check if it is perfect or not");

	PrintPerfectOrNot(Num);


	return 0;
}