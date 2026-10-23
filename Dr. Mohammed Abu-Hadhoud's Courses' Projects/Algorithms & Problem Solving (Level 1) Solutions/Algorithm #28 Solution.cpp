#include <iostream>
using namespace std;

enum enOddOrEven {Odd, Even};

int ReadNumber()
{
	int Num;

	cout << "Please enter a number: ";
	cin >> Num;

	return Num;
}

enOddOrEven CheckOddOrEven(int Number)
{
	if (Number % 2 == 0)
		return enOddOrEven::Even;
	else
		return enOddOrEven::Odd;
}

int SumOddFrom1ToN_UsingForLoop(int N)
{
	cout << "\nwith for loop:\n";

	int Sum = 0;

	// there are two ways.. this is the basic one.
	for (int i = 1; i <= N; i++)
	{
		if (CheckOddOrEven(i) == enOddOrEven::Odd) // if it is an odd number
			Sum += i;
	}

	return Sum;

	// the optimized way (increasing i by 2)
	//for (int i = 1; i <= N; i += 2)
	//{
	//	Sum += i; // no need for if statement here; it must be an odd number
	//}
}

int SumOddFrom1ToN_UsingWhileLoop(int N)
{
	cout << "\nwith while loop:\n";

	int Counter = 0, Sum = 0;

	while (Counter < N)
	{
		Counter++;

		if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
			Sum += Counter;
	}

	return Sum;
}

int SumOddFrom1ToN_UsingDoWhileLoop(int N)
{
	cout << "\nwith do-while loop:\n";

	int Counter = 0, Sum = 0;

	do
	{
		Counter++;
		if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
			Sum += Counter;

	} while (Counter < N);

	return Sum;
}

void PrintSum(int Sum)
{
	cout << "\nSum = " << Sum << endl;
}

int main()
{
	int N = ReadNumber();

	PrintSum(SumOddFrom1ToN_UsingForLoop(N));
	PrintSum(SumOddFrom1ToN_UsingWhileLoop(N));
	PrintSum(SumOddFrom1ToN_UsingDoWhileLoop(N));

	return 0;
}