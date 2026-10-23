#include <iostream>
using namespace std;

int x = 990;

void MyFunction1()
{
	int x = 500;

	cout << "In the MyFunction() x is " << x << endl;
}

int main()
{
	int x = 6;

	cout << "In the Main() x is " << x << endl;
	MyFunction1();

	::x++;
	::x = -1240;
	::x += 120;
	cout << "The global x is " << ::x << endl;

	return 0;
}