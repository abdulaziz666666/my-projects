#include <iostream>
using namespace std;

int main()
{
	short NumberOfStudents;

	do
	{
		cout << "Please enter the number of students: ";
		cin >> NumberOfStudents;
	} while (NumberOfStudents < 1);

	float* ptr;

	ptr = new float[NumberOfStudents];

	for (short i = 0; i < NumberOfStudents; i++)
	{
		cout << "Student [" << i + 1 << "] grade: ";
		cin >> *(ptr + i);
	}

	cout << "\n\nNow, the program will display the students' entered grades:\n";

	for (short i = 0; i < NumberOfStudents; i++)
		cout << "Student [" << i + 1 << "]: " << *(ptr + i) << endl;

	delete[]ptr;

	return 0;
}