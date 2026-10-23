#include <iostream>
#include <cmath>
using namespace std;

int ReadNumber(string Message)
{
	int Num;

	cout << Message << endl;
	cin >> Num;

	return Num;
}

// Instead of regular multiplying by -1, i had a brilliant solution.
// See, when multiplying a negative number by him self it would give
// you a squared-positive version of it. After that, you can take 
// the square root of it. Now, you have the absolute value of any number.
int MyABS1(int Num) // that is the "brilliant" solution you could say.
{
	// result can be bigger than integers
	// range before taking the square root;
	// so i convert it to double.
	return sqrt((double)Num * Num); 
}

// the "traditional" solution.
int MyABS2(int Num)
{
	if (Num < 0)
		Num *= -1; // or Num = -Num; all are same.

	return Num;
}

// Dr. Mohammed assumed the number might be float,
// while i didn't. Meaning my "brilliant" solution
// is completely wrong.
float MyABS3(float Num)
{
	if (Num < 0)
		Num *= -1; // or Num = -Num; all are same.

	return Num;
}

int main()
{
	float Num = ReadNumber("Please enter a number: ");

	cout << "My abs1 result:\t" << MyABS1(Num) << endl;	
	cout << "My abs2 result:\t" << MyABS2(Num) << endl;	
	cout << "My abs2 result:\t" << MyABS3(Num) << endl;
	cout << "C++ abs result:\t" << abs(Num) << endl;

	return 0;
}