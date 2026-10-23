#include <iostream>
#include <string>
using namespace std;

int main()
{
	string st1 = "43.22";

	int n1 = stoi(st1);
	float n2 = stof(st1);
	double n3 = stod(st1);

	cout << "Base string: " << st1 << endl;
	cout << "Converted int, float, and double: ";
	cout << n1 << " " << n2 << " " << n3 << endl;
	cout << endl;

	int n4 = 20;
	string st2 = to_string(n4);

	cout << "Base int: " << n4 << endl;
	cout << "Converted string: " << st2 << endl;
	cout << endl;

	double n5 = 33.5;
	string st3 = to_string(n5);

	cout << "Base int: " << n5 << endl;
	cout << "Converted string: " << st3 << endl;
	cout << endl;

	float n6 = 55.23;
	int n7 = int(n6);
	int n8 = (int)n6;
	int n9 = n6;
	string st4 = to_string(n6);

	cout << "Base float: " << n6 << endl;
	cout << "Converted int, and string: ";
	cout << n7 << " (Function) " << n8 << " (C Type) "<< n9 << " (Implicit) " << st4 << " (String) " << endl;

	return 0;
}