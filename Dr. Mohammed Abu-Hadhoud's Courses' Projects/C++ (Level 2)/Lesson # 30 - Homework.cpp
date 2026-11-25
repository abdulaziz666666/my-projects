#include <iostream>
#include <vector>
using namespace std;

struct stEmployee
{
	string FirstName;
	string LastName;
	float Salary;
};

void ReadEmployeeInfo(stEmployee& Employee)
{
	cout << "Please enter employee's first name: ";
	cin >> Employee.FirstName;

	cout << "Please enter employee's last name: ";
	cin >> Employee.LastName;

	cout << "Please enter employee's salary: ";
	cin >> Employee.Salary;
}

bool DoesUserWantToContinue()
{
	char Answer = 'Y';

	cout << "\nDo you want to continue adding another employee? (y/n): ";
	cin >> Answer;

	return (Answer == 'Y' || Answer == 'y');
}

void ReadEmployees(vector <stEmployee>& vEmployees)
{
	stEmployee TempEmployee;

	do
	{
		ReadEmployeeInfo(TempEmployee);
		vEmployees.push_back(TempEmployee);

	} while (DoesUserWantToContinue());
}

void PrintEmployees(vector <stEmployee>& vEmployees)
{
	cout << "The Entered Employees:\n";

	for (stEmployee& Employee : vEmployees)
	{
		cout << endl;
		cout << "First Name:\t" << Employee.FirstName << endl;
		cout << "Last Name:\t" << Employee.LastName << endl;
		cout << "Salary:\t\t" << Employee.Salary << endl;
		cout << endl;
	}
}

int main()
{
	vector <stEmployee> vEmployees;

	//ReadAllEmployeesInfo(vEmployees);
	//PrintEmployeesVector(vEmployees);
	ReadEmployees(vEmployees);
	PrintEmployees(vEmployees);

	return 0;
}