#include <iostream>
using namespace std;

int ReadNumber()
{
	unsigned Num;

	cout << "Please enter a number to sum odd numbers from 1 to it: ";
	cin >> Num;

	return Num;
}

int SumOddFrom1ToNum(unsigned Num)
{
	unsigned Sum = 0;

	//for (int i = 1; i <= Num; i += 2)
	//{
	//	Sum += i;
	//}

	int i = 1;

	while (i <= Num)
	{
		Sum += i;
		i++;
	}

	return Sum;
}

int main()
{
	unsigned Num = ReadNumber();
	unsigned OddSum = SumOddFrom1ToNum(Num);

	cout << OddSum << endl;

	return 0;
}