#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

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
		cout << Array.Elements[i] << " ";
	}

	cout << endl;
}

void CopyArray(stArray &FromArray, stArray &ToArray)
{
	ToArray.Length = FromArray.Length;

	for (int i = 0; i < FromArray.Length; i++)
		ToArray.Elements[i] = FromArray.Elements[i];
}

int main()
{
	srand((unsigned)time(NULL));

	stArray Array1, Array2;

	Array1.Length = ReadPositiveNumber("Please enter the array length (Max: 100)");

	FillArrayWithRandomNumbers(Array1, 1, 100);

	CopyArray(Array1, Array2);

	cout << "\nArray1 Elements:\t\t";
	PrintArray(Array1);

	cout << "Array2 Elements After Copying:\t";
	PrintArray(Array2);

	return 0;
}