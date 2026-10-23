#include <iostream>
using namespace std;

int ReadNum()
{
	int Num;
	cout << "Please enter a number to check if it is odd or even: ";
	cin >> Num;

	return Num;
}

bool isOddNumber(int Num)
{
	if (Num % 2 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PrintOddOrEven(int Num)
{
	if (isOddNumber(Num))
	{
		cout << "It is odd" << endl;
	}
	else
	{
		cout << "It is even" << endl;
	}
}

int main()
{	
	PrintOddOrEven(ReadNum());

	return 0;
}