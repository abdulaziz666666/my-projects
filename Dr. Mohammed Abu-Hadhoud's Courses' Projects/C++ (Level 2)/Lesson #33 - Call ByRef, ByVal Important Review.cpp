#include <iostream>
using namespace std;

void IncreaseByOne1(int X)
{
	cout << "X Address (val): " << &X << endl;
	X++;
}

void IncreaseByOne2(int &X)
{
	cout << "X Address (ref): " << &X << endl;
	X++;
}

int main()
{

	int A = 10;

	cout << "Base value: " << A << endl;
	cout << "Address: " << &A << endl;

	IncreaseByOne1(A);
	//cout << "By value: " << A << endl;

	IncreaseByOne2(A);
	//cout << "By reference: " << A << endl;

	return 0;
}