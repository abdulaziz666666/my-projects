#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	float Num;

	do
	{
		cout << Message << endl;
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

float CalculateMonthlyInstallment(float LoanAmount, float NumberOfMonths)
{
	return LoanAmount / NumberOfMonths;
}

int main()
{
	float LoanAmount = ReadPositiveNumber("Please enter the loan amount: ");
	float NumberOfMonths = ReadPositiveNumber("Please enter the number of months: ");

	cout << "\nYou will pay " << CalculateMonthlyInstallment(LoanAmount, NumberOfMonths) << " Monthly\n";
	return 0;
}