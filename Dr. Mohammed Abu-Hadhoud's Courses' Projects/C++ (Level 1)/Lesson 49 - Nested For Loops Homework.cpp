#include <iostream>
using namespace std;

void PrintAlphabetProbabilties()
{
	int Probabilties = 0;
	for (int i = 65; i <= 90; i++)
	{
		cout << "Letter: " << char(i) << endl;
		for (int j = 65; j <= 90; j++)
		{
			cout << char(i) << char(j) << endl;
			Probabilties++;
		}
		cout << "--------------------\n";
	}
	cout << Probabilties << endl;
}

void PrintNumberedTriangle(unsigned Height, bool isCountingUp, bool isVerticallyNormal)
{
	/*
	isCountingUp is represented by the inner loop.
	isVerticallyNormal is represented by the outer loop.
	*/

	if (isCountingUp && isVerticallyNormal)
	{
		/*
		1
		1 2
		1 2 3
		*/
		for (int i = 1; i <= Height; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}
	else if (!isCountingUp && isVerticallyNormal)
	{
		/*
		10
		10 9
		10 9 8
		*/
		for (int i = 1; i <= Height; i++)
		{
			for (int j = Height; j >= i; j--)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}
	else if (isCountingUp && !isVerticallyNormal)
	{
		/*
		1 2 3
		1 2
		1
		*/
		for (int i = Height; i >= 1; i--)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}
	else // !isCountingUp && !isVerticallyNormal
	{
		/*
		10 9 8
		10 9
		10
		*/
		for (int i = Height; i >= 1; i--)
		{
			for (int j = Height; j >= i; j--)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}
}

void PrintTriangleEndsWithNumber(unsigned LastNumber)
{
	for (int i = 1; i <= LastNumber; i++)
	{
		for (int j = i; j <= LastNumber; j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}

void PrintLettersTriangle(unsigned LastLetter)
{
	for (int i = 65; i < 65 + LastLetter; i++)
	{
		for (int j = 65; j <= i; j++)
		{
			cout << char(j) << " ";
		}
		cout << endl;
	}
}

void PrintTriangle(unsigned Height)
{
	for (int i = Height; i >= 1; i--)
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

	PrintNumberedTriangle(10, true, true);
	cout << endl;
	PrintNumberedTriangle(10, true, false);
	cout << endl;
	PrintNumberedTriangle(10, false, true);
	cout << endl;
	PrintNumberedTriangle(10, false, false);
	cout << endl;
	PrintTriangleEndsWithNumber(10);

	//PrintAlphabetProbabilties();
	cout << endl;
	PrintLettersTriangle(6);
	cout << endl;
	PrintTriangle(10);
	cout << endl;
	return 0;
}