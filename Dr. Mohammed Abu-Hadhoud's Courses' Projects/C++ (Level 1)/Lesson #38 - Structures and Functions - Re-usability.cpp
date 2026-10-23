#include <iostream>
#include <string>
using namespace std;

struct stInfo
{
	string FirstName;
	string LastName;
	unsigned short Age;
	string Phone;
};

void ReadInfo(stInfo &Info)
{
	cout << "Please Enter The Following:" << endl << endl;

	cout << "First Name: ";
	cin >> Info.FirstName;

	cout << "Last Name: ";
	cin >> Info.LastName;

	cout << "Age: ";
	cin >> Info.Age;

	cout << "Phone: ";
	cin >> Info.Phone;
}

void PrintInfo(stInfo Info)
{	
	cout << endl;
	cout << "**********************************" << endl;
	cout << "First Name:\t" << Info.FirstName << endl;
	cout << "Last Name:\t" << Info.LastName << endl;
	cout << "Age:\t\t" << Info.Age << endl;
	cout << "Phone:\t\t" << Info.Phone << endl;
	cout << "**********************************" << endl;
	cout << endl;
}

int main()
{
	stInfo Person1Info;
	ReadInfo(Person1Info);
	PrintInfo(Person1Info);

	stInfo Person2Info;
	ReadInfo(Person2Info);
	PrintInfo(Person2Info);

	return 0;
}