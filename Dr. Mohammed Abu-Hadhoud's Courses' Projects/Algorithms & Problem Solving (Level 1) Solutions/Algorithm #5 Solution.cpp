#include <iostream>
using namespace std;

struct stDriver
{
	int Age;
	bool HasDrivingLicense;
	bool HasRecommendation;
};

stDriver ReadDriverInfo()
{
	stDriver Driver;

	cout << "Please enter your age: ";
	cin >> Driver.Age;

	cout << "Do you have a driver license? (1 for yes/0 for no): ";
	cin >> Driver.HasDrivingLicense;

	cout << "Do you have a recommendation? (1 for yes/0 for no): ";
	cin >> Driver.HasRecommendation;

	return Driver;
}

bool IsAccepted(stDriver Driver)
{
	return ((Driver.Age >= 21 && Driver.HasDrivingLicense) || Driver.HasRecommendation);

	/* 
	Dr.Mohammed's way to make it in an if statement.

	if (Driver.HasRecommendation)
	{
		return true;
	}
	else
	{
		return (Driver.Age >= 21 && Driver.HasDrivingLicense);
	}
	*/
}

void PrintHiringResult(stDriver Driver)
{
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
	PrintHiringResult(ReadDriverInfo());
	return 0;
}