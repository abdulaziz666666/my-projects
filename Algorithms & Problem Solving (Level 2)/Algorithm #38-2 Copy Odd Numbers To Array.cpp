#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

enum enNumberType {Odd, Even};

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

enNumberType CheckNumberType(int Num)
{
	if (Num % 2 == 0)
		return enNumberType::Even;
	else
		return enNumberType::Odd;
}

void AddArrayElement(int Element, stArray &Array)
{
	Array.Elements[Array.Length++] = Element;
}

//void CopyOddNumbersToArray(stArray FromArray, stArray& ToArray)
void CopyOddNumbers(stArray FromArray, stArray& ToArray)
{
	ToArray.Length = 0;

	for (int i = 0; i < FromArray.Length; i++)
	{
		int Element = FromArray.Elements[i];

		if (CheckNumberType(Element) == enNumberType::Odd)
			AddArrayElement(Element, ToArray);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	stArray Array1, Array2;

	Array1.Length = ReadPositiveNumber("Please enter the array length (Max: 100)");
	FillArrayWithRandomNumbers(Array1, 1, 100);

	//CopyOddNumbersToArray(Array1, Array2);
	CopyOddNumbers(Array1, Array2);

	cout << "\nArray1 Elements:\t\t";
	PrintArray(Array1);

	cout << "Array2 Elements After Copying:\t";
	PrintArray(Array2);

	return 0;
}