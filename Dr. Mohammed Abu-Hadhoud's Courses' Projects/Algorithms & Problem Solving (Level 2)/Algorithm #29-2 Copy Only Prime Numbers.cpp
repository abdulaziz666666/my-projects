#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
using namespace std;

enum enPrimeOrNot {Prime, NotPrime};

struct stArray
{
	int Elements[100];
	int Length;
};

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

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(stArray& Array, int From, int To)
{
	for (int i = 0; i < Array.Length; i++)
		Array.Elements[i] = RandomNumber(From, To);
}

void PrintArray(stArray Array)
{
	cout << endl;

	for (int i = 0; i < Array.Length; i++)
	{
		cout << Array.Elements[i] << "\t";
	}

	cout << endl;
}

//enPrimeOrNot GetNumberType(int Num)
enPrimeOrNot CheckPrime(int Num) 
{
	// although it is efficient, it is hard to memorize.

	//if (Num == 2)
	//	return enPrimeOrNot::Prime;
	//else if (Num % 2 == 0) // but not 2.
	//	return enPrimeOrNot::NotPrime;
	//else if (Num < 2) // by definition.
	//	return enPrimeOrNot::NotPrime;

	//for (int i = 3; i < floor(Num / 2); i += 2) // floor() ensures it will be integer.
	//{
	//	if (Num % i == 0)
	//		return enPrimeOrNot::NotPrime;
	//}

	//return enPrimeOrNot::Prime;


	// basic way, but convenient for memorizing.
	int M = round(Num / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Num % Counter == 0)
			return enPrimeOrNot::NotPrime;
	}

	return enPrimeOrNot::Prime;

}

//void CopyPrimeNumbersFromArray(stArray& FromArray, stArray& ToArray)
void CopyOnlyPrimeNumbers(stArray FromArray, stArray& ToArray)
{
	ToArray.Length = 0;

	for (int i = 0; i < FromArray.Length; i++)
	{
		if (CheckPrime(FromArray.Elements[i]) == enPrimeOrNot::Prime)
		{
			ToArray.Elements[ToArray.Length] = FromArray.Elements[i];
			ToArray.Length++;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	stArray Array1, Array2;

	Array1.Length = ReadPositiveNumber("Please enter the array length (Max: 100)");

	FillArrayWithRandomNumbers(Array1, 1, 100);

	CopyOnlyPrimeNumbers(Array1, Array2);

	cout << "\nArray1 Elements:\t\t";
	PrintArray(Array1);

	cout << "Array2 Elements After Copying:\t";
	PrintArray(Array2);

	return 0;
}