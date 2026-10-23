#include <iostream>
using namespace std;

int main()
{
	unsigned short int Pennies, Nickles, Dimes, Quarters, Dollars;

	cout << "Please enter the numbers of the following:" << endl;

	cout << "Pennies: ";
	cin >> Pennies;

	cout << "Nickles: ";
	cin >> Nickles;

	cout << "Dimes: ";
	cin >> Dimes;
	
	cout << "Quarters: ";
	cin >> Quarters;

	cout << "Dollars: ";
	cin >> Dollars;

	cout << endl;

	float TotalPennies = Pennies + Nickles * 5 + Dimes * 10 + Quarters * 25 + Dollars * 100;
	float TotalDollars = TotalPennies / 100;

	cout << TotalPennies << " Pennies" << endl;
	cout << TotalDollars << " Dollars" << endl;

	return 0;
}