#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int& x = a; // reference variable (an alias for variable 'a').
	// Once a reference variable refer to a variable, it can not
	// refer to another one anymore. It will stick with it. Also,
	// both base variable and reference have the same address.

	cout << "a: " << a << endl;
	cout << "x: " << x << endl;
	cout << "Does A address & X address match?: " << (&a == &x) << endl;

	// Unlike references, pointers can change what they point to.
	int* p;
	p = &a;

	cout << endl;
	cout << "a address: " << &a << endl;
	cout << "p address: " << p << endl;
	cout << "a is " << a << " and p is " << *p << endl;

	int b = 20;
	p = &b;

	cout << endl;
	cout << "b address: " << &b << endl;
	cout << "p address: " << p << endl;
	cout << "b is " << b << " and p is " << *p << endl;

	// In conclusion, we can notice that pointers are much flexible and useful than references.

	return 0;
}