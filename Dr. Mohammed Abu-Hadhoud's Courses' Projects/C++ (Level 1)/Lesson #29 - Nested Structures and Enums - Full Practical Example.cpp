#include <iostream>
using namespace std;

//enum enGender { Male, Female };
//enum enMaritalStatus { Single, Married };
//enum enColor { Red, Green, Blue, Yellow, Black, White };
//
//struct stAddress
//{
//	string City;
//	string Country;
//};
//
//struct stContactInfo
//{
//	string PhoneNumber;
//	string Email;
//	string InstagramUsername;
//	stAddress Address;
//};
//
//struct Person
//{
//	string FirstName;
//	string LastName;
//
//	stContactInfo ContactInfo;
//
//	enGender Gender;
//	enMaritalStatus Status;
//	enColor FavouriteColor;
//};
//
//int main()
//{
//	Person Person1;
//
//	Person1.FirstName = "Abdulaziz";
//	Person1.LastName = "Al-Odail";
//
//	Person1.ContactInfo.PhoneNumber = "010104233";
//	Person1.ContactInfo.Email = "abduluziz37@gmail.com";
//	Person1.ContactInfo.InstagramUsername = "@Aziz.code6";
//
//	Person1.ContactInfo.Address.City = "Al-Hofuf";
//	Person1.ContactInfo.Address.Country = "Saudi Arabia";
//
//	Person1.Gender = enGender::Male;
//	Person1.Status = enMaritalStatus::Single;
//	Person1.FavouriteColor = enColor::Blue;
//
//	cout << "*************************************************************************\n";
//	cout << "Name:\t\t\t" << Person1.FirstName << " " << Person1.LastName << endl;
//	cout << "Age :\t\t\t" << Person1.Age << endl;
//	cout << "City:\t\t\t" << Person1.ContactInfo.Address.City << endl;
//	cout << "Country:\t\t" << Person1.ContactInfo.Address.Country << endl;
//	cout << "Gender:\t\t\t" << Person1.Gender << endl;
//	cout << "Married:\t\t" << Person1.Status << endl;
//	cout << "Favourite Color:\t" << Person1.FavouriteColor << endl;
//	cout << "Phone Number:\t\t" << Person1.ContactInfo.PhoneNumber << endl;
//	cout << "Email:\t\t\t" << Person1.ContactInfo.Email << endl;
//	cout << "Instagram Username:\t" << Person1.ContactInfo.InstagramUsername << endl;
//	cout << "*************************************************************************\n";
//
//	return 0;
//}

// طريقة الدكتور 

#include <iostream>
using namespace std;


enum enColor { Red, Green, Yellow, Blue };
enum enGendor { Male, Female };
enum enMaritalStatus { Single, Married };




struct stAddress
{
    string StreetName;
    string BuildingNo;
    string POBox;
    string ZipCode;
};




struct stContactInfo
{
    string Phone;
    string Email;
    stAddress Address;
};




struct stPerson
{


    string FirstName;
    string LastName;

    stContactInfo ContactInfo;


    enMaritalStatus MaritalStatues;
    enGendor Gendor;
    enColor FavourateColor;
};




int main()
{

    stPerson Person1;


    Person1.FirstName = "Mohammed";
    Person1.LastName = "Abu-Hadhoud";


    Person1.ContactInfo.Email = "xyz@xyz.com";
    Person1.ContactInfo.Phone = "+961000000999";
    Person1.ContactInfo.Address.POBox = "7777";
    Person1.ContactInfo.Address.ZipCode = "11194";
    Person1.ContactInfo.Address.StreetName = "Queen1 Street";
    Person1.ContactInfo.Address.BuildingNo = "313";

    Person1.Gendor = enGendor::Male;
    Person1.MaritalStatues = enMaritalStatus::Married;
    Person1.FavourateColor = enColor::Green;


    cout << Person1.ContactInfo.Address.StreetName << endl;



    return 0;
}
