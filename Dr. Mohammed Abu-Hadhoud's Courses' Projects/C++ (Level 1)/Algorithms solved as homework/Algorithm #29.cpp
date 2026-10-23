#include <iostream>
using namespace std;

int ReadNumber()
{
	unsigned Num;

	cout << "Please enter a number to sum even numbers from 2 to it: ";
	cin >> Num;

	return Num;
}

int SumEvenFrom1ToNum(unsigned Num)
{
	unsigned Sum = 0;

	//for (int i = 2; i <= Num; i += 2)
	//{
	//	Sum += i;
	//}
	
	int i = 2; // as starting from 0 is no sense.

	while (i <= Num)
	{ 
		Sum += i;
		i += 2;
	}

	return Sum;
}

int main()
{
	unsigned Num = ReadNumber();
	unsigned EvenSum = SumEvenFrom1ToNum(Num);

	cout << EvenSum << endl;

	return 0;
}