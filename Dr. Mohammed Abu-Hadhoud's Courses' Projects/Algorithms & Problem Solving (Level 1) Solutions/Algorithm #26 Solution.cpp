#include <iostream>
using namespace std;

int ReadNumber()
{
	int Num;

	cout << "Please enter a number: ";
	cin >> Num;

	return Num;
}

//void PrintFrom1ToNumber(int Number)
void PrintFrom1ToN_UsingFor(int N)
{
	cout << "\nUsing For Loop:\n";

	for (int i = 1; i <= N; i++)
	{
		cout << i << endl;
	}
}

void PrintFrom1ToN_UsingWhile(int N)
{
	cout << "\nUsing While Loop:\n";
	
	int Counter = 1;
	
	while (Counter <= N)
	{
		cout << Counter << endl;
		Counter++;
	}
}

void PrintFrom1ToN_UsingDoWhile(int N)
{
	cout << "\nUsing Do-While Loop:\n";

	int Counter = 1;
	
	do
	{
		cout << Counter << endl;
		Counter++;
	
	} while (Counter <= N);
}

int main()
{
	int N = ReadNumber();

	//PrintFrom1ToNumber(ReadNumber());
	PrintFrom1ToN_UsingFor(N);
	PrintFrom1ToN_UsingWhile(N);
	PrintFrom1ToN_UsingDoWhile(N);
	return 0;
}