#include <iostream>
using namespace std;

int main()
{
	float TotalBill, PaidCash;

	cout << "Please enter the total bill: ";
	cin >> TotalBill;

	cout << "Please enter the paid cash: ";
	cin >> PaidCash;

	float Remainder = TotalBill - PaidCash;

	cout << endl << Remainder << endl;

	return 0;
}