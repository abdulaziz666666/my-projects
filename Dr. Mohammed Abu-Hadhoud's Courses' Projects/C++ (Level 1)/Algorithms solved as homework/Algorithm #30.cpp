#include <iostream>
using namespace std;

int ReadPositiveNumber()
{
	int Num;

	cout << "Please enter a positive number to print it\'s factorial: " << endl;
	cin >> Num;

	while (Num < 0)
	{
		cout << "Wrong number, please enter a positive number to print it\'s factorial: " << endl;
		cin >> Num;
	}

	return Num;
}

int GetFactorial(unsigned Num)
{
	unsigned Factorial = 1;

	//for (int i = Num; i >= 1; i--)
	//{
	//	Factorial *= i;
	//}
	
	unsigned i = Num;

	while (i >= 1)
	{
		Factorial *= i;
		i--;
	}

	return Factorial;
}

int main()
{
	unsigned PositiveNumber = ReadPositiveNumber();
	cout << PositiveNumber << "! = " << GetFactorial(PositiveNumber) << endl;

	return 0;
}