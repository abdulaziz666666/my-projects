#include <iostream>
using namespace std;

//int ReadNumber()
int ReadPositiveNumber(string Message)
{
	int Num;

	do
	{
		cout << Message << endl;
		cin >> Num;

	} while (Num < 0);

	return Num;
}

//int FactorialOfN(int N)
int Factorial(int N)
{
	int F = 1;

	for (int i = N; i >= 1; i--)
		F *= i;

	return F;
}

int main()
{
	//int Num = ReadNumber();
	cout << Factorial(ReadPositiveNumber("Please enter a positive number: ")) << endl;

	return 0;
}