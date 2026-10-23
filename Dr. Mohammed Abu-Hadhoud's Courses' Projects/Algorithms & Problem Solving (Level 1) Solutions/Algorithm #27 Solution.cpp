#include <iostream>
using namespace std;

int ReadNumber()
{
	int Num;

	cout << "Please enter a number: ";
	cin >> Num;

	return Num;
}

void PrintFromNTo1_UsingFor(int N)
{
	cout << "\nUsing For Loop:\n";

	for (int i = N; i >= 1; i--)
	{
		cout << i << endl;
	}
}

void PrintFromNTo1_UsingWhile(int N)
{
	cout << "\nUsing While Loop:\n";

	// dr. Mohammed's way
	int Counter = N + 1; 

	while (Counter > 1)
	{
		Counter--;
		cout << Counter << endl;
	}

	// my way
	//int Counter = N;
	//while (Counter >= 1)
	//{
	//	cout << Counter << endl;
	//	Counter--;
	//}
}

void PrintFromNTo1_UsingDoWhile(int N)
{
	cout << "\nUsing Do-While Loop:\n";

	int Counter = N + 1;

	do
	{
		Counter--;
		cout << Counter << endl;

	} while (Counter > 1);

	//int Counter = N;

	//do
	//{
	//	cout << Counter << endl;
	//	Counter--;

	//} while (Counter >= 1);
}

int main()
{
	int N = ReadNumber();

	PrintFromNTo1_UsingFor(N);
	PrintFromNTo1_UsingWhile(N);
	PrintFromNTo1_UsingDoWhile(N);
	return 0;
}