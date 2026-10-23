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

void PrintInvertedLetterPattern(int Number)
{
	cout << endl;
	// this solution is mine. i think this way is the best.
	for (int i = Number; i >= 1; i--) // from N letter to first letter
	{
		for (int j = 1; j <= i; j++)
			cout << char(64 + i); // at least it would be 64 + 1 which is A.

		cout << endl;
	}

	// i am not comfortable with dr.Mohammed's solution; it is messy.
	
	//for (int i = 65 + Number - 1; i >= 65; i--)
	//{
	//	for (int j = 1; j <= Number - ((65 + Number - 1) - i); j++)
	//	{
	//		cout << char(i);
	//	}
	//	cout << endl;
	//}
}

int main()
{	
	int Num = ReadPositiveNumber("Please enter a number");

	PrintInvertedLetterPattern(Num);

	return 0;
}