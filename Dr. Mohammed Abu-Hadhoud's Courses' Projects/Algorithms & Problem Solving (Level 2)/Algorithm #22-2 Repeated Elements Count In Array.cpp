#include <iostream>
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
		cout << Message << ": ";
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

stArray ReadArray()
{
	stArray Array;

	Array.Length = ReadPositiveNumber("Please enter the array length");

	cout << "\nPlease enter array elements:\n";

	for (int i = 0; i < Array.Length; i++)
		Array.Elements[i] = ReadPositiveNumber("Element [" + to_string(i + 1) + "]");

	return Array;
}

//void PrintArrayElements(stArray Array)
void PrintArray(stArray Array)
{
	for (int i = 0; i < Array.Length; i++)
	{
		cout << Array.Elements[i] << " ";
	}

	cout << endl;
}

//int CountOfNumberInArray(int NumberToCheck, stArray Array)
int TimesRepeated(int NumberToCheck, stArray Array)
{
	int Counter = 0;

	for (int i = 0; i < Array.Length; i++)
	{
		if (Array.Elements[i] == NumberToCheck)
			Counter++;
	}

	return Counter;
}

void PrintNumberRepetitionInArray(int NumberToCheck, stArray Array)
{
	cout << endl;
	cout << NumberToCheck << " is repeated ";
	cout << TimesRepeated(NumberToCheck, Array);
	cout << " time(s)\n";
}

int main()
{
	stArray Array = ReadArray();
	int NumberToCheck = ReadPositiveNumber("\nPlease enter the number you want to check");

	cout << "\nOriginal Array: ";
	PrintArray(Array);
	
	PrintNumberRepetitionInArray(NumberToCheck, Array);

	return 0;
}