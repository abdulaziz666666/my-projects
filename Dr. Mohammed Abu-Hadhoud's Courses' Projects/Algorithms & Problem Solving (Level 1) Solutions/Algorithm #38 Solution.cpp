#include <iostream>
using namespace std;

enum enPrimeOrNot {Prime, NotPrime};

int ReadPositiveNumber()
{
	int Num;

	do
	{
		cout << "Please enter a positive number: ";
		cin >> Num;

	} while (Num <= 0);

	return Num;
}

enPrimeOrNot CheckNumberType(int Num)
{
	if (Num < 2) 
		return enPrimeOrNot::NotPrime;

	// there is a problem here.. i'm not sure about rounding.
	// i feel it is important to check all possible numbers, but is it?
	// now i know odd numbers division by 2 would give a decimal result
	// for sure, but does rounding realy help the checking goal.. ?
	for (int Counter = 2; Counter <= round(Num / 2); Counter++)
	{
		cout << Counter << endl;

		if (Num % Counter == 0)
			return enPrimeOrNot::NotPrime;
	}

	return enPrimeOrNot::Prime;
}

void PrintNumberType(int Num)
{
	if (CheckNumberType(Num) == enPrimeOrNot::Prime)
		cout << "\nPrime\n";
	else
		cout << "\nNOT prime\n";

}

int main()
{
	PrintNumberType(ReadPositiveNumber());
	return 0;
}