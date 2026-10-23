#include <iostream>
using namespace std;

int main()
{
	float BillValue;

	cout << "Please enter the bill value: ";
	cin >> BillValue;

	BillValue = BillValue * 1.1;
	BillValue = BillValue * 1.16;

	cout << endl << BillValue << endl;

	return 0;
}