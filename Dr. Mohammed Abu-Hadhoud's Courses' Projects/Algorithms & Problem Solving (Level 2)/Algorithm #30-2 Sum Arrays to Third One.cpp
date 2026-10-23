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
	cout << endl;

	for (int i = 0; i < Array.Length; i++)
	{
		cout << Array.Elements[i] << "\t";
	}

	cout << endl;
}

// i'm not sure about the name "ToArray". it is meaningful somehow, but not really good name.
//void Sum2ArraysToArray(stArray Array1, stArray Array2, stArray &ToArray)
void SumOf2ArraysToArray(stArray Array1, stArray Array2, stArray &SumArray)
{
	for (int i = 0; i < Array1.Length; i++)
		SumArray.Elements[i] = Array1.Elements[i] + Array2.Elements[i];
}

int main()
{
	srand((unsigned)time(NULL));

	stArray Array1, Array2, SumArray;

	 Array1.Length = ReadPositiveNumber("Please enter the array length (Max: 100)");
	 SumArray.Length = Array2.Length = Array1.Length;

	FillArrayWithRandomNumbers(Array1, 1, 100);
	FillArrayWithRandomNumbers(Array2, 1, 100);

	SumOf2ArraysToArray(Array1, Array2, SumArray);

	cout << "\nArray1 Elements:";
	PrintArray(Array1);

	cout << "\nArray2 Elements:";
	PrintArray(Array2);

	cout << "\nSum Of Array1 and Array2 Elements:";
	PrintArray(SumArray);

	return 0;
}