#include <iostream>
using namespace std;

int ReadNum()
{
	int Num;
	cout << "Please enter a number: " << endl;
	cin >> Num;

	return Num;
}

int SumWhatBelow50()
{
	int Sum = 0;
	int Num;

	for (int i = 1; i <= 5; i++)
	{
		Num = ReadNum();

		if (Num >= 50)
		{
			cout << "It won\'t be calculated as it is greater than or equal 50" << endl;
			continue;
		}

		Sum += Num;
	}

	return Sum;
}

int main()
{
	int SumOf5Numbers = SumWhatBelow50();
	cout << endl << "Sum = " << SumOf5Numbers << endl;

	return 0;
}