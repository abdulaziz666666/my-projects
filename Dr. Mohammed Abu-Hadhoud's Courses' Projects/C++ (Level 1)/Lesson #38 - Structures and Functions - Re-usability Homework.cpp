#include <iostream>
using namespace std;

struct stAddress
{
	string City;
	string Country;
};

struct stPerson
{
	string FirstName;
	string LastName;
	stAddress Address;

	unsigned short int Age;
	float MonthlySalary;
	char Gender;
	bool isMarried;
};

void ReadInfo(stPerson &Person)
{
	cout << "Please enter the following:" << endl << endl;

	cout << "first name: ";
	cin >> Person.FirstName;

	cout << "last name: ";
	cin >> Person.LastName;

	cout << "Age: ";
	cin >> Person.Age;
		 
	cout << "City: ";
	cin >> Person.Address.City;

	cout << "Country: ";
	cin >> Person.Address.Country;

	cout << "Monthly Salary: ";
	cin >> Person.MonthlySalary;

	cout << "Gender (M/F): ";
	cin >> Person.Gender;

	cout << "Are you married (1 for yes/0 for no): ";
	cin >> Person.isMarried;

	cout << endl << endl;
}

void PrintInfo(stPerson Person)
{
	cout << "*****************************************" << endl;

	cout << "first name:\t\t" << Person.FirstName << endl;
	cout << "last name:\t\t" << Person.LastName << endl;
	cout << "City:\t\t\t" << Person.Address.City << endl;
	cout << "Country:\t\t" << Person.Address.Country << endl;
	cout << "Monthly Salary:\t\t" << Person.MonthlySalary << endl;
	cout << "Yearly Salary:\t\t" << Person.MonthlySalary * 12 << endl;
	cout << "Gender:\t\t\t" << Person.Gender << endl;
	cout << "Married:\t\t" << Person.isMarried << endl;

	cout << "*****************************************" << endl;
	cout << endl;
}

int main()
{
	stPerson Person1Info;

	ReadInfo(Person1Info);
	PrintInfo(Person1Info);

	return 0;
}