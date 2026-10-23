#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enNumberType { Odd, Even };

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

enNumberType CheckNumberType(int Num)
{
	if (Num % 2 == 0)
		return enNumberType::Even;
	else
		return enNumberType::Odd;
}

// Dr.Mohammed named them "OddCount, EvenCount", which is better.
// the reason i didn't take those name conventions as Dr.Mohammed 
// taught us to name as i did: a meaningful name; thats why i am
// not a great names selector.

// another thing, Dr.Mohammed made these functions directly without
// an enum for NumberType (AKA: Odd and Even). He also didn't use
// any structures to make an array, which is not convenient.
// As arrays always come with their length variable, we had better
// group them in a simple unified structure. I noticed 
// Dr.Mohammed has a lot of contradictions like that one.
int CountEvenNumbersInArray(stArray Array)
{
	int Counter = 0;

	for (int i = 0; i < Array.Length; i++)
		if (CheckNumberType(Array.Elements[i]) == enNumberType::Even)
			Counter++;

	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	stArray Array;
	Array.Length = ReadPositiveNumber("Please enter the array length (Max: 100)");

	FillArrayWithRandomNumbers(Array, 1, 100);

	cout << "\nArray Elements: ";
	PrintArray(Array);

	cout << "\nThere are " << CountEvenNumbersInArray(Array);
	cout << " Even Number(s) in the Array\n";

	return 0;
}