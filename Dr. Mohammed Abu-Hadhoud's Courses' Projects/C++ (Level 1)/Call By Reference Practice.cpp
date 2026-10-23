#include <iostream>
#include <string>
using namespace std;

struct stStudent
{
	string Name;
	string AcademicNumber;
	char Gender;
	float GPA;
};

// This Procedure Called Student Parameter By VALUE
void PrintStudentCard(stStudent Student)
{
	cout << "Welcome, This is your student card:" << endl << endl;

	cout << "*******************************************" << endl;
	cout << "Name:\t\t\t" << Student.Name << endl;
	cout << "Academic Number:\t" << Student.AcademicNumber << endl;
	cout << "Gender:\t\t\t" << Student.Gender << endl;
	cout << "GPA:\t\t\t" << Student.GPA << endl;
	cout << "*******************************************" << endl;
}

// This Procedure Called Student Parameter By REFERENCE
void Register(stStudent &Student)
{
	cout << "< | Register Page | >" << endl << endl;

	cout << "Name:" << endl;
	getline(cin, Student.Name);

	cout << endl;

	cout << "Academic Number:" << endl;
	cin >> Student.AcademicNumber;

	cout << endl;

	cout << "Gender (M/F):" << endl;
	cin >> Student.Gender;

	cout << endl;

	cout << "GPA: " << endl;
	cin >> Student.GPA;

	cout << endl;
}

void EditStudentInfo(stStudent &Student, string InfoToEdit, string NewValue)
{
	if (InfoToEdit == "Name")
	{
		Student.Name = NewValue;
	}
	//else if (InfoToEdit == "Gender") 
	//{
	//	Student.Gender = NewValue;
	//}
	//else if (InfoToEdit == "GPA") 
	//{
	//	cout << "GPA: ";
	//}
	//else if (InfoToEdit == "Academic Number") 
	//{
	//	cout << "Academic Number: ";
	//}
	
	cout << endl << "Changes Saved Successfully!" << endl;
}

int main()
{
	stStudent Student;
	
	Register(Student);
	PrintStudentCard(Student);
	EditStudentInfo(Student, "Name", "Abdullah");
	PrintStudentCard(Student);

	return 0;
}