#include <iostream>
using namespace std;

// Dr. Mohammed named it "stInfo" but i'm good with "stDriver".
struct stDriver
{
	int Age;
	bool HasDrivingLicense;
};

stDriver ReadDriverInfo()
{
	stDriver Driver;

	cout << "Please enter your age: ";
	cin >> Driver.Age;

	cout << "Do you have a driver license? (1 for yes/0 for no): ";
	cin >> Driver.HasDrivingLicense;

	return Driver;
}

//bool CheckDriverInfo(stDriver Driver)
bool IsAccepted(stDriver Driver)
{
	return (Driver.Age >= 21 && Driver.HasDrivingLicense);
	//if (Driver.Age >= 21 && Driver.HasDrivingLicense)
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
}

//void PrintHiringResult(bool TermsAreMet)
void PrintHiringResult(stDriver Driver)
{
	//if (TermsAreMet)
	if (IsAccepted(Driver))
	{
		cout << endl << "Hired" << endl;
	}
	else
	{
		cout << endl << "Rejected" << endl;
	}
}

int main()
{
	//PrintHiringResult(CheckDriverInfo(Driver));
	PrintHiringResult(ReadDriverInfo());

	return 0;
}