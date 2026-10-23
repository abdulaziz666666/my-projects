#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	float BillValue;

	do
	{
		cout << Message << " (Should be positive): ";
		cin >> BillValue;

	} while (BillValue <= 0);

	return BillValue;
}
//
//float CalculateServiceFee(float BillValue)
//{
//	return BillValue * 1.1;
//}
//
//float CalculateSalesTax(float BillValueWithServiceFee)
//{
//	return BillValueWithServiceFee * 1.16;
//}

float CalculateTotalBill(float BilValue)
{
	const float SERVICE_FEE_PERCENTAGE = 1.1;
	const float SALES_TAX_PERCENTAGE = 1.16;
	return BilValue * SERVICE_FEE_PERCENTAGE * SALES_TAX_PERCENTAGE;
}

void PrintTotalBill(float BillValue)
{
	cout << endl;
	cout << "The Original Bill Value: " << BillValue << endl;
	cout << "Total Bill Value with Service Fee & Sales Tax: " << CalculateTotalBill(BillValue) << endl;
}

int main()
{
	float BillValue = ReadPositiveNumber("Please enter the bill value");
	PrintTotalBill(BillValue);

	return 0;
}