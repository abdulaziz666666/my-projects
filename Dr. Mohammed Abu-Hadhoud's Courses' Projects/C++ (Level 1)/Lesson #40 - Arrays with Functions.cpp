#include <iostream>
using namespace std;

void ReadArrayData(int x[3])
{
	cout << "Enter number1: ";
	cin >> x[0];

	cout << "Enter number2: ";
	cin >> x[1];

	cout << "Enter number3: ";
	cin >> x[2];
}

void PrintArrayData(int x[3])
{
	cout << endl;
	cout << "Number1: " << x[0] << endl;
	cout << "Number2: " << x[1] << endl;
	cout << "Number3: " << x[2] << endl;
}

int main()
{
	int x[3];

	ReadArrayData(x);
	PrintArrayData(x);

	return 0;
}