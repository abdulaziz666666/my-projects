#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	float Num;

	do
	{
		cout << Message << " (Should be positive): ";
		cin >> Num;

	} while (Num <= 0);

	return Num;
}

/*
float ReadTotalBill()
{
	float TotalBill;

	cout << "Please enter the total bill: ";
	cin >> TotalBill;

	return TotalBill;
}

float ReadPaidCash()
{
	float PaidCash;

	cout << "Please enter the paid cash: ";
	cin >> PaidCash;

	return PaidCash;
}
*/

float CalculateRemainder(float TotalBill, float PaidCash)
{
	return PaidCash - TotalBill;
}

//void PrintRemainder(float Remainder)
//{
//	cout << "The remainder is " << Remainder << endl;
//}

void PrintRemainder(float TotalBill, float PaidCash)
{
	cout << endl;
	cout << "Total:\t" << TotalBill << endl;
	cout << "Paid:\t" << PaidCash << endl;
	cout << "*********************" << endl;
	cout << "Remainder: " << CalculateRemainder(TotalBill, PaidCash) << endl;
}

int main()
{
	//float Remainder = CalculateRemainder(ReadTotalBill(), ReadPaidCash());
	//PrintRemainder(Remainder);

	float TotalBill = ReadPositiveNumber("Please enter the total bill");
	float PaidCash = ReadPositiveNumber("Please enter the paid cash");

	PrintRemainder(TotalBill, PaidCash);

	return 0;
}