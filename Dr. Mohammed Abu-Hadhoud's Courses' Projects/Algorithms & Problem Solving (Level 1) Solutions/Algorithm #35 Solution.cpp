#include <iostream>
using namespace std;

//struct stMoney
struct stPiggyBank
{
	int Dollars, Quarters, Dimes, Nickels, Pennies;
};

stPiggyBank ReadPiggyBankContent()
{
	stPiggyBank PiggyBank;

	cout << "Please enter the following:\n\n";

	cout << "Dollars: ";
	cin >> PiggyBank.Dollars;

	cout << "Quarters: ";
	cin >> PiggyBank.Quarters;

	cout << "Dimes: ";
	cin >> PiggyBank.Dimes;

	cout << "Nickels: ";
	cin >> PiggyBank.Nickels;

	cout << "Pennies: ";
	cin >> PiggyBank.Pennies;

	return PiggyBank;
}

int CalculateTotalPennies(stPiggyBank PiggyBank)
{
	int Pennies = PiggyBank.Pennies;

	Pennies += PiggyBank.Dollars * 100;
	Pennies += PiggyBank.Quarters * 25;
	Pennies += PiggyBank.Dimes * 10;
	Pennies += PiggyBank.Nickels * 5;

	return Pennies;
}

float CalculateTotalDollars(int TotalPennies)
{
	return (float)TotalPennies / 100;
}

int main()
{
	stPiggyBank PiggyBank = ReadPiggyBankContent();

	int TotalPennies = CalculateTotalPennies(PiggyBank);
	float TotalDollars = CalculateTotalDollars(TotalPennies);

	cout << "\nTotal Pennies = " << TotalPennies << endl;
	cout << "Total Dollars = " << TotalDollars << endl;

	return 0;
}