#include <iostream>
using namespace std;

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

void PrintLetterPattern(int Number)
{
	cout << endl;

	// my way.
	//for (int i = 1; i <= Number; i++)
	//{
	//	for (int j = 1; j <= i; j++)
	//		cout << char(64 + i);

	//	cout << endl;
	//}

	// Dr.Mohammed's way.
	for (int i = 65; i <= 65 + Number - 1; i++)
	{
		for (int j = 1; j <= i - 65 + 1; j++)
			cout << char(i);

		cout << endl;
	}
}

int main()
{
	int Num = ReadPositiveNumber("Please enter a number");

	PrintLetterPattern(Num);
	return 0;
}