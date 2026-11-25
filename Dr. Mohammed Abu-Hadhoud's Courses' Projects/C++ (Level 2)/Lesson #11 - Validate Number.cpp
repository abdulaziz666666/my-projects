#include <iostream>
using namespace std;

int ReadNumber()
{
	int Num;

	cout << "Please enter a number: ";
	cin >> Num;

	while (cin.fail())
	{
		cin.clear();
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Invalid number, please enter a valid one: " << endl;
		cin >> Num;
	}

	return Num;
}


int main()
{
	int Num = ReadNumber();

	cout << "The number was " << Num << endl;

	return 0;
}