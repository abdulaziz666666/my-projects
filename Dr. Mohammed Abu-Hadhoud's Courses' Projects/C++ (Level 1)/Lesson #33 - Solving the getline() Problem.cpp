#include <iostream>
#include <string>
using namespace std;

struct stEmployee
{
	int Number;
	string Name;
	string Country;
};

stEmployee Employee1;

void ReceiveEmployeeInfo()
{
	cout << "Please enter employee number: ";
	cin >> Employee1.Number;

	cout << "Please enter your name: ";
	cin.ignore(1, '\n'); // So it doesn't consider the ENTER key press as an input.
	getline(cin, Employee1.Name);

	cout << "Please enter your country: ";
	cin >> Employee1.Country;

	cout << endl;
}

void PrintEmployeeInfo()
{
	cout << "Number:\t\t" << Employee1.Number << endl;
	cout << "Name:\t\t" << Employee1.Name << endl;
	cout << "Country:\t" << Employee1.Country << endl;
}

int main()
{
	ReceiveEmployeeInfo();
	PrintEmployeeInfo();

	return 0;
}