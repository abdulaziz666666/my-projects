#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct stArray
{
	int Elements[100];
	int Length;
};

void FillArrayManually(stArray &Array)
{
	int arr[10] = { 10, 10, 10, 50, 50, 70, 70, 70, 70, 90 };

	for (int i = 0; i < 10; i++)
	{
		Array.Elements[i] = arr[i];
	}
}

int GetRandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

// not required for this algorithm but i made it to practice
// and i ALHAMDULILLAH done it successfully.
void FillArrayRandomlyWithRepetition(stArray& Array, int From, int To)
{
	int RandomNumber;
	int NumberOfRepitions;
	int LastIndex;

	for (int i = 0; i < Array.Length; i++)
	{
		RandomNumber = GetRandomNumber(From, To);
		NumberOfRepitions = GetRandomNumber(1, Array.Length) % (Array.Length - i);

		for (int j = i; j <= NumberOfRepitions + i; j++)
		{
			Array.Elements[j] = RandomNumber;
			LastIndex = j;
		}

		i = LastIndex;
	}
}

void FillArrayRandomly(stArray& Array, int From, int To, bool WithRepeatition)
{
	if (WithRepeatition) 
		FillArrayRandomlyWithRepetition(Array, From, To);
	else
	{
		for (int i = 0; i < Array.Length; i++)
			Array.Elements[i] = GetRandomNumber(From, To);
	}
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

// my first try.
void CopyDistinctNumbersFromArray1(stArray FromArray, stArray& ToArray)
{
	int LastNumber = 0;
	ToArray.Length = 0; // instead of counter.

	for (int i = 0; i < FromArray.Length; i++)
	{
		if (LastNumber == FromArray.Elements[i])
			continue;
		else
		{
			ToArray.Elements[ToArray.Length] = FromArray.Elements[i];
			LastNumber = ToArray.Elements[ToArray.Length];
			ToArray.Length++;
		}
	}
}

// before Dr.Mohammed solves it and while he is explaining
// the requirements, his explainations inspire me
// of another way of solution, which is much better and clearer. 
void CopyDistinctNumbersFromArray2(stArray FromArray, stArray& ToArray)
{
	ToArray.Length = 0; // instead of counter.

	for (int i = 0; i < FromArray.Length; i++)
	{
		if (TimesRepeated(FromArray.Elements[i], ToArray) >= 1)
			continue;
		else
			ToArray.Elements[ToArray.Length++] = FromArray.Elements[i];
	}
}

int FindNumberIndexInArray(stArray Array, int Num)
{
	for (int i = 0; i < Array.Length; i++)
	{
		if (Array.Elements[i] == Num)
			return i;
	}

	return -1; // didn't find it
}

bool IsElementOfArray(stArray Array, int Element)
{
	return FindNumberIndexInArray(Array, Element) != -1;
}

void AddArrayElement(stArray &Array, int Element)
{
	Array.Elements[Array.Length++] = Element;
}

// as doctor solves it. i completly forgot IsElementOfArray() function.
void CopyDistinctNumbersFromArray3(stArray FromArray, stArray& ToArray)
{
	ToArray.Length = 0; // instead of counter.

	for (int i = 0; i < FromArray.Length; i++)
	{
		if (!IsElementOfArray(ToArray, FromArray.Elements[i]))
			AddArrayElement(ToArray, FromArray.Elements[i]);
	}

}

int main()
{	
	srand((unsigned)time(NULL));

	stArray Array1, Array2;

	Array1.Length = 10;
	//FillArrayManually(Array1);
	FillArrayRandomly(Array1, 1, 100, true);

	cout << "\nArray Elements: ";
	PrintArray(Array1);

	CopyDistinctNumbersFromArray3(Array1, Array2);

	PrintArray(Array2);

	return 0;
}