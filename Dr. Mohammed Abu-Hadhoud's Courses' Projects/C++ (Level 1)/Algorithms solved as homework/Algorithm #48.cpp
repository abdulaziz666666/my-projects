#include <iostream>
using namespace std;

int main()
{
	float LoanAmount;
	unsigned short int Months;

	cout << "Please enter the loan amount: ";
	cin >> LoanAmount;

	cout << "Please enter how many months do you want to pay in: ";
	cin >> Months;

	cout << endl;

	unsigned int MonthlyPayment = LoanAmount / Months;

	cout << MonthlyPayment << endl;

	return 0;
}