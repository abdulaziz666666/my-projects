#include <iostream>
using namespace std;

int main()
{
	int Num1, Num2;

	cout << "Please enter the first number: ";
	cin >> Num1;

	cout << "Please enter the second number: ";
	cin >> Num2;

	cout << endl;

	cout << Num1 << " + " << Num2 << " = " << Num1 + Num2 << endl;
	cout << Num1 << " - " << Num2 << " = " << Num1 - Num2 << endl;
	cout << Num1 << " * " << Num2 << " = " << Num1 * Num2 << endl;
	cout << Num1 << " / " << Num2 << " = " << Num1 / Num2 << endl;
	cout << Num1 << " % " << Num2 << " = " << Num1 % Num2 << endl;

	return 0;
}