#include <iostream>
using namespace std;

int main()
{
	int A, B;

	cout << "Please enter the first Numebr A: ";
	cin >> A;

	cout << "Please enter the first Numebr B: ";
	cin >> B;

	cout << endl;

	cout << A << "\t=\t" << B << " is " << (A == B) << endl;
	cout << A << "\t!=\t" << B << " is " << (A != B) << endl;
	cout << A << "\t<\t" << B << " is " << (A < B) << endl;
	cout << A << "\t>\t" << B << " is " << (A > B) << endl;
	cout << A << "\t<=\t" << B << " is " << (A <= B) << endl;
	cout << A << "\t>=\t" << B << " is " << (A >= B) << endl;

	return 0;
}