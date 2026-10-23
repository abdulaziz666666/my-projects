#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
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
	for (int i = 0; i < Array.Length; i++)
	{
		cout << Array.Elements[i] << "\t";
	}

	cout << endl;
}

enPrimeOrNot CheckPrime(int Num)
{
	if (Num < 2) // 1 or negative.
		return enPrimeOrNot::NotPrime;

	int M = round(Num / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Num % Counter == 0)
			return enPrimeOrNot::NotPrime;
	}

	return enPrimeOrNot::Prime;
}

void AddArrayElement(int Element, stArray& Array)
{
	Array.Elements[Array.Length++] = Element;
}

void CopyPrimeNumbers(stArray FromArray, stArray& ToArray)
{
	ToArray.Length = 0;

	for (int i = 0; i < FromArray.Length; i++)
	{
		int Element = FromArray.Elements[i];

		if (CheckPrime(Element) == enPrimeOrNot::Prime)
			AddArrayElement(Element, ToArray);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	stArray Array1, Array2;

	Array1.Length = ReadPositiveNumber("Please enter the array length (Max: 100)");
	FillArrayWithRandomNumbers(Array1, 1, 100);

	CopyPrimeNumbers(Array1, Array2);

	cout << "\nArray1 Elements:\t\t";
	PrintArray(Array1);
	
	cout << "Array2 Elements After Copying:\t";
	PrintArray(Array2);

	return 0;
}