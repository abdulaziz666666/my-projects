#include <iostream>
using namespace std;

int main()
{
	//int A = 10, B = 20;
	//
	//A++; 
	//B--;
	//
	//cout << "A = " << A << endl;
	//cout << "B = " << B << endl;

	int A = 10, B = A++;
	
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	
	B = ++A;

	cout << "A = " << A << endl;
	cout << "B = " << B << endl;

	return 0;
}