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

int SumEvenFrom1ToN_UsingFor(int N)
{
	cout << "\nfor loop:\n";

	int Sum = 0;

	for (int i = 1; i <= N; i++)
	{
		if (CheckOddOrEven(i) == enOddOrEven::Even)
			Sum += i;
	}

	return Sum;
}

int SumEvenFrom1ToN_UsingWhile(int N)
{
	cout << "\nwhile loop:\n";

	int Counter = 0, Sum = 0;
	
	while (Counter < N)
	{
		Counter++;

		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
			Sum += Counter;
	}

	return Sum;
}

int SumEvenFrom1ToN_UsingDoWhile(int N)
{

	cout << "\ndo while loop:\n";

	int Counter = 0, Sum = 0;

	do
	{
		Counter++;

		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
			Sum += Counter;

	} while (Counter < N);

	return Sum;
}


int main()
{
	int N = ReadNumber();

	cout << SumEvenFrom1ToN_UsingFor(N) << endl;
	cout << SumEvenFrom1ToN_UsingWhile(N) << endl;
	cout << SumEvenFrom1ToN_UsingDoWhile(N) << endl;

	return 0;
}