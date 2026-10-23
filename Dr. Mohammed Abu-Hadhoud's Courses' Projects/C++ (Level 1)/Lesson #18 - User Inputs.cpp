#include <iostream>
using namespace std;

int main()
{
	char MyChar;
	int MyNumber;

	cout << "Please enter a character: ";
	cin >> MyChar;

	cout << "Please enter a number: ";
	cin >> MyNumber;

	cout << "You entered " << MyChar << " as a character." << endl;
	cout << "Also, you entered " << MyNumber << " as a number." << endl;

	return 0;
}