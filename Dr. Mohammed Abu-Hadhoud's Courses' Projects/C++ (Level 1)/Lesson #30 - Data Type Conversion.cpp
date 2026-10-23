#include <iostream>
#include <string>
using namespace std;

int main()
{
	//int IntNum;
	//double DoubleNum  = 9.99;

	// Implicit Conversion تحويل غير صريح
	//IntNum = DoubleNum; // لا ينصح به

	//// Both conversions are explicit (صريح).
	//IntNum = (int)DoubleNum; // The C Way.
	//IntNum = int(DoubleNum); // The int() Function Way.

	//cout << DoubleNum << endl;
	//cout << IntNum << endl;

	//string Str = "123.456";

	//int IntNum = stoi(Str);
	//float FloatNum = stof(Str);
	//double DoubleNum = stod(Str);

	//cout << IntNum << endl << FloatNum << endl << DoubleNum << endl;

	int Num1 = 123;
	float Num2 = 1.23;

	string Str1, Str2;

	Str1 = to_string(Num1);
	Str2 = to_string(Num2);

	cout << Str1 << endl << Str2 << endl;

	return 0;
}