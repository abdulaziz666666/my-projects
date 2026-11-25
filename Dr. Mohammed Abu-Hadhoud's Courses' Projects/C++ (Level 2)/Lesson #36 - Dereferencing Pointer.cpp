#include <iostream>
using namespace std;

int main()
{
	int a = 10;

	cout << a << endl;
	cout << &a << endl;

	int* p = &a;

	cout << p << endl;
	cout << *p << endl;

	*p = 20;

	cout << a << endl;
	cout << *p << endl; // *p = de-referencing - p = &a referencing.

	a = 30;

	cout << a << endl;
	cout << *p << endl;
	
	return 0;
}