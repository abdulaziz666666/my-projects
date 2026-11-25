#include <iostream>
#include <vector>
using namespace std;

struct stEmployee
{
	string FirstName;
	string LastName;
	float Salary;
};

void FillEmployeeInfo(stEmployee& Employee, string FirstName, string LastName, float Salary)
{
	Employee.FirstName = FirstName;
	Employee.LastName = LastName;
	Employee.Salary = Salary;
}

void PrintEmployeesVector(vector <stEmployee>& vEmployees)
{
	for (stEmployee& Employee : vEmployees)
	{
		cout << "First Name:\t" << Employee.FirstName << endl;
		cout << "Last Name:\t" << Employee.LastName << endl;
		cout << "Salary:\t\t" << Employee.Salary << endl;
		cout << endl;
	}
}

int main()
{
	vector <stEmployee> vEmployees;

	stEmployee TempEmpolyee;

	FillEmployeeInfo(TempEmpolyee, "Ahmed", "Al-Obaidah", 9820);
	vEmployees.push_back(TempEmpolyee);

	FillEmployeeInfo(TempEmpolyee, "Abdulaziz", "Al-Odail", 2790);
	vEmployees.push_back(TempEmpolyee);

	FillEmployeeInfo(TempEmpolyee, "Abdulmuhsin", "Al-Hammad", 1255);
	vEmployees.push_back(TempEmpolyee);

	PrintEmployeesVector(vEmployees);

	return 0;
}