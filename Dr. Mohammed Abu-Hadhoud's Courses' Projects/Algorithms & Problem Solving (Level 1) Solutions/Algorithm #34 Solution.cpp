#include <iostream>
using namespace std;

float ReadTotalSales()
{
	float TotalSales;

	cout << "Please enter the total sales: ";
	cin >> TotalSales;

	return TotalSales;
}

float GetCommisionPercentage(float TotalSales)
{
	if (TotalSales >= 1000'000)
		return 0.01;

	else if (TotalSales >= 500'000)
		return 0.02;

	else if (TotalSales >= 100'000)
		return 0.03;

	else if (TotalSales >= 50'000)
		return 0.05;

	else
		return 0;
}

float CalculateTotalCommision(float TotalSales)
{
	return TotalSales * GetCommisionPercentage(TotalSales);
}

void PrintCommisionResult(float TotalSales)
{
	cout << "\nPercentage: " << GetCommisionPercentage(TotalSales) * 100 << "%" << endl;
	cout << "Total commision: " << CalculateTotalCommision(TotalSales) << endl;
} 

int main()
{
	float TotalSales = ReadTotalSales();
	PrintCommisionResult(TotalSales);

	return 0;
}