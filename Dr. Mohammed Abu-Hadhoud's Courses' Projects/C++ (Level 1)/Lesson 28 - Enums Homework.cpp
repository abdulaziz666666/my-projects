#include <iostream>
using namespace std;

enum enGender {Male, Female};
enum enMaritalStatus {Single, Married};
enum enColor {Red, Green, Blue, Yellow, Black, White};

struct stAddress
{
	string City;
	string Country;
};

struct stContactInfo
{
	string PhoneNumber;
	string Email;
	string InstagramUsername;
	stAddress Address;
};

struct Person
{
	string FirstName;
	string LastName;
	stContactInfo ContactInfo;

	unsigned short int Age;
	float MonthlySalary;
	enGender Gender;
	enMaritalStatus Status;
	enColor FavouriteColor;
};

int main()
{
	Person Person1;

	Person1.FirstName = "Abdulaziz";
	Person1.LastName = "Al-Odail";

	Person1.Age = 19;

	Person1.ContactInfo.Address.City = "Al-Hofuf";
	Person1.ContactInfo.Address.Country = "Saudi Arabia";

	Person1.MonthlySalary = 990;

	Person1.Gender = enGender::Male;

	Person1.Status = enMaritalStatus::Single;

	Person1.FavouriteColor = enColor::Blue;

	Person1.ContactInfo.PhoneNumber = "010104233";
	Person1.ContactInfo.Email = "abduluziz37@gmail.com";
	Person1.ContactInfo.InstagramUsername = "@Aziz.code6";

	cout << "*************************************************************************\n";
	cout << "Name:\t\t\t" << Person1.FirstName << " " << Person1.LastName << endl;
	cout << "Age :\t\t\t" << Person1.Age << endl;
	cout << "City:\t\t\t" << Person1.ContactInfo.Address.City << endl;
	cout << "Country:\t\t" << Person1.ContactInfo.Address.Country << endl;
	cout << "Monthly Salary:\t\t" << Person1.MonthlySalary << endl;
	cout << "Yearly Salary:\t\t" << Person1.MonthlySalary * 12 << endl;
	cout << "Gender:\t\t\t" << Person1.Gender << endl;
	cout << "Married:\t\t" << Person1.Status << endl;
	cout << "Favourite Color:\t" << Person1.FavouriteColor << endl;
	cout << "Phone Number:\t\t" << Person1.ContactInfo.PhoneNumber << endl;
	cout << "Email:\t\t\t" << Person1.ContactInfo.Email << endl;
	cout << "Instagram Username:\t" << Person1.ContactInfo.InstagramUsername << endl;
	cout << "*************************************************************************\n";

	return 0;
}