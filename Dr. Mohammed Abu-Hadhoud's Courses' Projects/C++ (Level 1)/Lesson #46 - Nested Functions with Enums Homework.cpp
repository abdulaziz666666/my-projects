#include <iostream>
using namespace std;

enum enCarCompany { Toyota = 1, Nissan, Hyundai };

void PrintAvailableCarCompanies()
{
	cout << "*************************" << endl;
	cout << "   Available Companies   " << endl;
	cout << "*************************" << endl;
	cout << "1: Toyota" << endl;
	cout << "2: Nissan" << endl;
	cout << "3: Hyundai" << endl;
	cout << "*************************" << endl;

	cout << endl;
}

enCarCompany ReadCarCompany()
{
	int CompanyNumber;

	cout << "Please enter the number of the company: ";
	cin >> CompanyNumber;

	return (enCarCompany)CompanyNumber;
}

string GetCarCompanyName(enCarCompany CarCompany)
{
	switch (CarCompany)
	{
	case enCarCompany::Toyota:
		return "Toyota";
		break;
	case enCarCompany::Nissan:
		return "Nissan";
		break;
	case enCarCompany::Hyundai:
		return "Hyundai";
		break;
	default:
		return "Wrong Selection";
	}
}

int main()
{
	PrintAvailableCarCompanies();
	string SelectedCarCompany = GetCarCompanyName(ReadCarCompany());

	cout << "You Selected " << SelectedCarCompany << endl;

	return 0;
}