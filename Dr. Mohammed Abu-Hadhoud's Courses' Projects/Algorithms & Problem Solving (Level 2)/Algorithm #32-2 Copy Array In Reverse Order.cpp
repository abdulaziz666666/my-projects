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

void CopyArrayInReverseOrder(stArray SourceArray, stArray& DistinationArray)
{
	int LastIndex = SourceArray.Length - 1;

	// As Dr.Mohammed requested: a normal for-loop that assigns the elements reversely.
	// I see this way is better as it is more clearer to the reader to understand.
	// You can understand it is saying "assign the first element of this array 
	// with the value of the last element of that array".
	for (int i = 0; i <= LastIndex; i++) 
		// indexes: (0, 10), (1, 9), (2, 8), etc.
		DistinationArray.Elements[i] = SourceArray.Elements[LastIndex - i]; 
}

int main()
{
	srand((unsigned)time(NULL));

	stArray Array1, Array2;

	Array1.Length = ReadPositiveNumber("Please enter the array length (Max: 100)");
	Array2.Length = Array1.Length;

	FillArrayWithRandomNumbers(Array1, 1, 100);
	CopyArrayInReverseOrder(Array1, Array2);

	cout << "\nArray 1 Elements: ";
	PrintArray(Array1);

	cout << "Array 2 Elements: ";
	PrintArray(Array2);

	return 0;
}