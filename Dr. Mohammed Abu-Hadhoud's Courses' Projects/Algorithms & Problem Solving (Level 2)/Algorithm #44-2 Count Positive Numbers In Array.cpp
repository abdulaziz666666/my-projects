#include <iostream>
#include <cstdlib>
#include <ctime>
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

int CountPositiveNumbersInArray(stArray Array)
{
	int Counter = 0;

	for (int i = 0; i < Array.Length; i++)
		if (Array.Elements[i] >= 0)
			Counter++;

	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	stArray Array;
	Array.Length = ReadPositiveNumber("Please enter the array length (Max: 100)");

	FillArrayWithRandomNumbers(Array, -100, 100);

	cout << "\nArray Elements: ";
	PrintArray(Array);

	cout << "\nThere are " << CountPositiveNumbersInArray(Array);
	cout << " Positive Number(s) in the Array\n";

	return 0;
}