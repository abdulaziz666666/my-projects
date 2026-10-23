#include <iostream>
using namespace std;


struct PersonName
{
	string FirstName;
	string LastName;
};

struct PersonAddress
{
	string City;
	string Country;
};

struct PersonContactInfo
{
	string PhoneNumber;
	string Email;
	string InstagramUsername;
};

struct Person
{
	PersonName FullName;
	PersonAddress Address;
	unsigned short int Age;
	float MonthlySalary;
	char Gender;
	bool isMarried;
	PersonContactInfo ContactInfo;
};

int main()
{
	Person Person1;
	
	cout << "Welcome!\n\nYou need to enter your information to fill up the ID Card." << endl;
	
	cout << "First Name: ";
	cin >> Person1.FullName.FirstName;
	
	cout << "Last Name: ";
	cin >> Person1.FullName.LastName;
	
	cout << "Age: ";
	cin >> Person1.Age;
	
	cout << "City: ";
	cin >> Person1.Address.City;
	
	cout << "Country: ";
	cin >> Person1.Address.Country;
	
	cout << "Monthly Salary: ";
	cin >> Person1.MonthlySalary;
	
	cout << "Gender (enter M for Male\\F for Female): ";
	cin >> Person1.Gender;
	
	cout << "Are you married? (enter 1 for Yes\\0 for No): ";
	cin >> Person1.isMarried;

	cout << "Phone Number: ";
	cin >> Person1.ContactInfo.PhoneNumber;

	cout << "Email: ";
	cin >> Person1.ContactInfo.Email;

	cout << "Instagram Username: ";
	cin >> Person1.ContactInfo.InstagramUsername;
	
	cout << endl;
	
	cout << "*************************************************************************\n";
	cout << "Name:\t\t\t" << Person1.FullName.FirstName << " " << Person1.FullName.LastName << endl;
	cout << "Age :\t\t\t" << Person1.Age << endl;
	cout << "City:\t\t\t" << Person1.Address.City << endl;
	cout << "Country:\t\t" << Person1.Address.Country << endl;
	cout << "Monthly Salary:\t\t" << Person1.MonthlySalary << endl;
	cout << "Yearly Salary:\t\t" << Person1.MonthlySalary * 12 << endl;
	cout << "Gender:\t\t\t" << Person1.Gender << endl;
	cout << "Married:\t\t" << Person1.isMarried << endl;
	cout << "Phone Number:\t\t" << Person1.ContactInfo.PhoneNumber << endl;
	cout << "Email:\t\t\t" << Person1.ContactInfo.Email << endl;
	cout << "Instagram Username:\t" << Person1.ContactInfo.InstagramUsername << endl;
	cout << "*************************************************************************\n";

    return 0;
}