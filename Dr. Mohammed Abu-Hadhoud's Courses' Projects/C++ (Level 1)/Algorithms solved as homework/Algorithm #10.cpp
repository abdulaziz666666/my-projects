#include <iostream>
using namespace std;

int main()
{
	unsigned short int Mark1, Mark2, Mark3;

	cout << "Please enter the first mark: ";
	cin >> Mark1;

	cout << "Please enter the second mark: ";
	cin >> Mark2;

	cout << "Please enter the third mark: ";
	cin >> Mark3;

	cout << endl;

	unsigned short int Average = (Mark1 + Mark2 + Mark3) / 3;
	cout << Average << endl;

	return 0;
}