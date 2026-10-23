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

string GetReversedNumber(int Num)
{
	string strNumber = to_string(Num);
	int NumberOfDigits = strNumber.length();

	string ReversedStrNumber = "";
	for (int i = NumberOfDigits - 1; i >= 0; i--)
		ReversedStrNumber += strNumber[i];

	return ReversedStrNumber;
}

void PrintReversedNumber(int Num)
{
	cout << endl;
	cout << "it was\t\t" << Num << endl;
	cout << "it becomes\t" << GetReversedNumber(Num) << endl;
}

// as -i thought- Dr.Mohammed ordered.. which i don't see is convenient.
void PrintReversedNumber2(int Num)
{
	string strNumber = to_string(Num);
	int NumberOfDigits = strNumber.length();

	string ReversedStrNumber = "";
	for (int i = NumberOfDigits - 1; i >= 0; i--)
		cout << strNumber[i] << endl;
}

// the real way Dr.Mohammed wanted.. perfect..
void PrintDigits(int Num)
{
	int Remainder = 0;

	while (Num > 0)
	{
		Remainder = Num % 10;
		Num = Num / 10;
		cout << Remainder << endl;
	}
}

int main()
{
	int Num = ReadPositiveNumber("Please enter a number to reverse it");
	PrintDigits(Num);

	return 0;
}