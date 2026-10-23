#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct stArray
{
	int Elements[100];
	int Length;
};

//int ReadPositiveNumber(string Message)
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

//int IndexOfNum(stArray Array, int Num)
int FindNumberIndexInArray(stArray Array, int Num) // i have to find better name conventions.
{
	for (int i = 0; i < Array.Length; i++)
	{
		if (Array.Elements[i] == Num)
			return i;
	}

	return -1; // didn't find it
}

void PrintIndex(short Index)
{
	if (Index == -1) // didn't find it
		cout << "The number is not found :-(\n";
	else
	{
		cout << "The number is founded at position " << Index << endl;
		cout << "The number's order is " << Index + 1 << endl;
	}
}

int ReadNumber()
{
	int Num;

	cout << "Please enter a number: ";
	cin >> Num;

	return Num;
}

int main()
{
	srand((unsigned)time(NULL));

	stArray Array;
	Array.Length = ReadPositiveNumber("Please enter the array length (Max: 100)");

	FillArrayWithRandomNumbers(Array, 1, 100);

	cout << "\nArray Elements: ";
	PrintArray(Array);

	short NumberToCheck = ReadNumber();
	cout << "\nNumber you are looking for is " << NumberToCheck << endl;
	PrintIndex(FindNumberIndexInArray(Array, NumberToCheck));

	return 0;
}