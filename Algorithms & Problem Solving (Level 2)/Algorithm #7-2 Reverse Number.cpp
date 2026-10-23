#include <iostream>
#include <string>
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
// my way
//int ReverseNumber(int Number)
//{
//	string StrNumber = to_string(Number);
//	string ReversedStrNumber = "";
//
//	int Remainder = 0;
//	while (Number > 0)
//	{
//		Remainder = Number % 10;
//		Number /= 10;
//		ReversedStrNumber += to_string(Remainder);
//	}
//
//	return stoi(ReversedStrNumber);
//}

// Dr.Mohammed's way
int ReverseNumber2(int Number)
{
	int Remainder, ReversedNumber = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		ReversedNumber = ReversedNumber * 10 + Remainder;
	}

	return ReversedNumber;
}

int main()
{
	int Num = ReadPositiveNumber("Please enter a number");
	cout << "Reverse is " << ReverseNumber2(Num) << endl;

	return 0;
}