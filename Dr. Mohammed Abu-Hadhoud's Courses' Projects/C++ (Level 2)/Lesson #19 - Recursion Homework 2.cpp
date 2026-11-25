#include <iostream>
using namespace std;

// my own solution
int MyPow1(int Base, int Power, int Result = 1)
{
	if (Power > 0)
	{
		Result *= Base;
		return MyPow1(Base, Power - 1, Result);
	}

	else
		return Result;
}

// Dr. Mohammed's solution
int MyPow2(int Base, int Power)
{
	if (Power == 0)
		return 1;
	else
		return Base * MyPow2(Base, Power - 1);
}

// training..
int MySum(int Arr[10], int Length)
{
	if (Length == 1)
		return Arr[0];
	else
		return Arr[Length - 1] + MySum(Arr, Length - 1);
}

int main()
{
	int Base = 2, Power = 5;
	int Result = MyPow1(Base, Power);

	cout << Result << endl;

	Result = MyPow2(Base, Power);

	cout << Result << endl;

	int Arr[10] = { 1, 2, 3, 4 };
	cout << MySum(Arr, 4);

	return 0;
}