#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 50;

	int* p = &a;

	cout << "Variable Value:\t\t" << a << endl;
	cout << "Variable Address:\t" << &a << endl;

	cout << "Variable Value:\t\t" << b << endl;
	cout << "Variable Address:\t" << &b << endl;

	cout << "Pointer value:\t\t" << p << endl;
	
	p = &b;

	cout << "Pointer value:\t\t" << p << endl;

	return 0;
}