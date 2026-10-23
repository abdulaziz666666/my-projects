#include <iostream>
using namespace std;

void DifferenceBetweenForAndWhileLoop()
{
	cout << "For Loop:" << endl;
	for (int i = 1; i <= 5; i++)
	{
		cout << i << endl;
	}

	cout << "While Loop" << endl;
	int i = 1;
	while (i <= 5)
	{
		cout << i << endl;
		i++;
	}
}

int ReadPositiveNumber()
{
	int Number;
	
	cout << "Please enter a positive number: " << endl;
	cin >> Number;

	while (Number < 0)
	{
		cout << "Wrong number, please enter a positive number: " << endl;
		cin >> Number;
	}

	return Number;
}

int ReadIntegerInRange(int From, int To)
{
	int Number;
	
	cout << "Please enter a number from " << From << " to " << To << ": " << endl;
	cin >> Number;

	while (Number < From || Number > To)
	{
		cout << "Wrong Number, please enter a number from " << From << " to " << To << ": " << endl;
		cin >> Number;
	}

	return Number;
}

int main()
{
	//DifferenceBetweenForAndWhileLoop();
	
	//int PositiveNumber = ReadPositiveNumber();
	//cout << endl << "You entered " << PositiveNumber << endl;;

	int RangedNumber = ReadIntegerInRange(18, 45);
	cout << endl << "You entered " << RangedNumber << endl;;


	return 0;
}