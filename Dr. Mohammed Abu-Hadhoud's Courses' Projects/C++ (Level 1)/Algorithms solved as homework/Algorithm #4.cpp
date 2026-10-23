#include <iostream>
using namespace std;

struct stDriver
{
	unsigned short Age;
	bool HasDrivingLicense;
};

void ReadDriverInfo(stDriver &Driver)
{
	cout << "Please enter your age: ";
	cin >> Driver.Age;

	cout << "Do you have a driving license? (1 for yes/0 for no): ";
	cin >> Driver.HasDrivingLicense;

	cout << endl;
}

void PrintHiredOrRejected(stDriver &Driver)
{
	if (Driver.Age > 21 && Driver.HasDrivingLicense)
	{
		cout << "Hired" << endl;
	}
	else
	{
		cout << "Rejected" << endl;
	}
}

int main()
{
	stDriver Driver;

	ReadDriverInfo(Driver);
	PrintHiredOrRejected(Driver);

	return 0;
}