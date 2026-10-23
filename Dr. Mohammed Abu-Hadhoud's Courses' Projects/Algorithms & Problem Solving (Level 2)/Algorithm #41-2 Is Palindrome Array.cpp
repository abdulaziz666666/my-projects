#include <iostream>
using namespace std;

struct stArray
{
	int Elements[100];
	int Length;
};

void PrintArray(stArray Array)
{
	cout << endl;

	for (int i = 0; i < Array.Length; i++)
	{
		cout << Array.Elements[i] << "\t";
	}

	cout << endl;
}

void AddArrayElement(stArray& Array, int Element)
{
	Array.Elements[Array.Length++] = Element;
}

void FillArrayManually(stArray& Array)
{
	Array.Length = 0;
	AddArrayElement(Array, 1);
	AddArrayElement(Array, 2);
	AddArrayElement(Array, 3);
	AddArrayElement(Array, 2);
	AddArrayElement(Array, 1);
}

void CopyArrayInReverseOrder(stArray SourceArray, stArray& DistinationArray)
{
	for (int i = 0; i < SourceArray.Length; i++)
		AddArrayElement(DistinationArray, SourceArray.Elements[SourceArray.Length - 1 - i]);
}

// wrong way.. i'm not sure why it isn't working, though.
bool IsPalindromeArray1(stArray Array)
{
	stArray ReversedArray;
	ReversedArray.Length = Array.Length;
	CopyArrayInReverseOrder(Array, ReversedArray);

	return Array.Elements == ReversedArray.Elements;
}

bool IsPalindromeArray2(stArray Array)
{
	for (int i = 0; i < Array.Length; i++)
	{
		if (Array.Elements[i] != Array.Elements[Array.Length - 1 - i])
			return false;
	}
	return true;
}

int main()
{
	stArray Array1;

	FillArrayManually(Array1);

	cout << "Array Elements: ";
	PrintArray(Array1);

	if (IsPalindromeArray2(Array1))
		cout << "Yes, the array is Palindrome.\n";
	else
		cout << "No, the array is NOT Palindrome.\n";

	return 0;
}