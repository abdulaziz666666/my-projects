#include <iostream>
#include <cmath>
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

//float CalculateNumberOfMonths(float LoanAmount, float Monthlyinstallment)
float TotalMonths(float LoanAmount, float Monthlyinstallment)
{
	//return (float)LoanAmount / Monthlyinstallment; // This is how Dr. Mohammed wrote it.
	return ceil(LoanAmount / Monthlyinstallment);	 // but i think that is more convinient.
}

int main()
{
	float LoanAmount = ReadPositiveNumber("Please enter the loan amount: ");
	float Monthlyinstallment = ReadPositiveNumber("Please enter the monthly payment: ");

	cout << "\nYou will pay along " << TotalMonths(LoanAmount, Monthlyinstallment) << " Months\n";

	return 0;
}