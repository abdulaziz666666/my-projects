//Temperature Converter (Fahrenheit to Celsius)
#include <iostream>
using namespace std;
int main() {
	double fahrenheit;
	double celsius;
	cout << "Enter temperature in Fahrenheit: ";
	cin >> fahrenheit;
	// Convert Fahrenheit to Celsius
	celsius = (float)5 / 9 * (fahrenheit - 32);
	cout << fahrenheit << " degrees Fahrenheit is equal to " << celsius << " degrees Celsius." << endl;
	return 0;
}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	string name = "abdulaziz";
//	int age = 19;
//	float PI = 3.14;
//
//	cout << "My name is " << name << "\n, i am " << age << " years old";
//	return 0;
//}

