#include <iostream>
using namespace std;

void ReadTotalSales(float& TotalSales)
{
	cout << "Please enter the total sales: ";
	cin >> TotalSales;

	cout << endl;
}

float GetCommisionPercentage(float TotalSales)
{
	if (TotalSales > 1000000)
	{
		return 0.01;
	}
	else if (TotalSales >= 500000)
	{
		return 0.02;
	}
	else if (TotalSales >= 100000)
	{
		return 0.03;
	}
	else if (TotalSales >= 50000)
	{
		return 0.05;
	}
	else
	{
		return 0;
	}
}

void PrintSalesCommision(float TotalSales)
{
	float Percentage = GetCommisionPercentage(TotalSales);

	cout << "Your Sales Commision is " << TotalSales * Percentage << endl;
	cout << "With a percentage of " << 100 * Percentage << "%" << endl;
}

int main()
{
	float TotalSales;

	ReadTotalSales(TotalSales);
	PrintSalesCommision(TotalSales);

	return 0;
}