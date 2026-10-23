#include <iostream>
using namespace std;

int main()
{
	float Base, Height;

	cout << "Please enter the base: ";
	cin >> Base;

	cout << "Please enter the Height: ";
	cin >> Height;

	cout << endl;

	float Area = Base / 2 * Height;
	cout << Area << endl;

	return 0;
}