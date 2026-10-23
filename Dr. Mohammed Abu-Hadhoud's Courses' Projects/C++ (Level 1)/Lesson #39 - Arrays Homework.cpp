#include <iostream>
using namespace std;

void ReadGrades(float Grades[3])
{
	cout << "Please enter the first grade: " << endl;
	cin >> Grades[0];

	cout << "Please enter the second grade: " << endl;
	cin >> Grades[1];

	cout << "Please enter the third grade: " << endl;
	cin >> Grades[2];
}

float Average(float Grades[3])
{
	return (Grades[0] + Grades[1] + Grades[2]) / 3;
}

void PrintAverage(float Grades[3])
{
	cout << "\n*******************************\n\n";
	cout << "The average of the grades is " << Average(Grades) << endl;
}

int main()
{	
	// معلومة مهمة: المصفوفات تُستدعى بالمرجع بشكل افتراضي

	float Grades[3];

	ReadGrades(Grades);
	PrintAverage(Grades);

	return 0;
}