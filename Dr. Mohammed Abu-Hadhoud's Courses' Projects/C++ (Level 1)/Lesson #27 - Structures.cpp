#include <iostream>
using namespace std;

struct OwnerAddress
{
    string Street1;
    string POSTALBOX;
};

struct CarOwner
{
    string FullName;
    string PhoneNumber;
    OwnerAddress Address;
};

struct Car 
{
    CarOwner Owner;
    string Brand;
    string Model;
    int Year;
};

int main()
{
    Car MyCar1, MyCar2;

    MyCar1.Brand = "Toyota";
    MyCar1.Model = "Corolla";
    MyCar1.Year = 2026;
    MyCar1.Owner.FullName = "Someone Al-Somwanee";
    MyCar1.Owner.PhoneNumber = "0505050505";
    MyCar1.Owner.Address.Street1 = "Al-Bourini";
    MyCar1.Owner.Address.POSTALBOX = "32312";

    MyCar2.Brand = "Nissan";
    MyCar2.Model = "Sunny";
    MyCar2.Year = 2022;
    MyCar2.Owner.FullName = "Abdulaziz Al-Odail";
    MyCar2.Owner.PhoneNumber = "0512345678";
    MyCar2.Owner.Address.Street1 = "Al-Bourini";
    MyCar2.Owner.Address.POSTALBOX = "32312";

    cout << MyCar1.Brand << "\t" << MyCar1.Model << "\t" << MyCar1.Year << endl;
    cout << "Owner: " << MyCar1.Owner.FullName << endl;
    cout << "Number: " << MyCar1.Owner.PhoneNumber << endl;

    cout << endl;

    cout << MyCar2.Brand << "\t" << MyCar2.Model << "\t" << MyCar2.Year << endl;
    cout << "Owner: " << MyCar2.Owner.FullName << endl;
    cout << "Number: " << MyCar2.Owner.PhoneNumber << endl;

    return 0;
}