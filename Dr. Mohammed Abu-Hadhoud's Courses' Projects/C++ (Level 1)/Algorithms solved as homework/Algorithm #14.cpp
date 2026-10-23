#include <iostream>
using namespace std;

void SwapNumbers(int &Num1, int &Num2)
{
	int Temp = Num1;
	Num1 = Num2;
	Num2 = Temp;
}

int main()
{
	int Num1, Num2;
	
	cout << "Please enter a number: ";
	cin >> Num1;

	cout << "Please enter another number: ";
	cin >> Num2;

	cout << endl;

	cout << "You entered:\n" << Num1 << endl << Num2 << endl;
	SwapNumbers(Num1, Num2);
	cout << "Now they become:\n" << Num1 << endl << Num2 << endl;

	// The Old Way.
	//cout << endl;

	//cout << "You entered:\n" << Num1 << endl << Num2 << endl;

	//Temp = Num1;
	//Num1 = Num2;
	//Num2 = Temp;

	//cout << "Now they become:\n" << Num1 << endl << Num2 << endl;

	return 0;
}