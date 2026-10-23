#include <iostream>
using namespace std;

int main()
{
	float LoanAmount, MonthlyPayment;

	cout << "Please enter the loan amount: ";
	cin >> LoanAmount;

	cout << "Please enter the monthly payment: ";
	cin >> MonthlyPayment;

	cout << endl;

	float Months = ceil(LoanAmount / MonthlyPayment);

	cout << Months << " Months." << endl;

	return 0;
}