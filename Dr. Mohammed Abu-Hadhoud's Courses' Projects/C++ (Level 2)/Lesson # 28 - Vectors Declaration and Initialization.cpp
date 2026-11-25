#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// std::vector
	vector <int> vNumbers = { 124, 7546, 12, 875, 3, 314, 0, 23, 0 };

	cout << "Integers Vector: ";

	for (int &Number : vNumbers)
	{
		cout << Number << "  ";
	}

	cout << endl;

	return 0;
}