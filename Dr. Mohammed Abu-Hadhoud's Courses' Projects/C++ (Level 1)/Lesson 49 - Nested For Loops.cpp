#include <iostream>
using namespace std;

void PrintMultiplicationTable()
{
	for (int i = 1; i <= 12; i++)
	{
		cout << "( " << i << " )" << endl;

		for (int j = 1; j <= 12; j++)
		{
			cout << i << " x " << j << "\t= " << i * j << endl;
		}

		cout << "--------------------" << endl;
	}
}

void PrintSquare()
{
	for (int i = 1; i <= 10; i++)
	{
		for (int i = 1; i <= 20; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void PrintTriangle()
{
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

int main()
{
	//PrintMultiplicationTable();
	//PrintSquare();
	PrintTriangle();
	return 0;
}