#include <iostream>
using namespace std;

void MyFunction()
{
	// Functions return values, on the other hand, procedures don't.
	cout << "This is my first procedure, it got executed ;-)" << endl;
}

string MyFunction2()
{
	return "This is my first returning value function, this is the value.";
}

int MyFunction3()
{
	int x = 10, y = 20;
	return x * y;
}

float MyFunction4()
{
	float x = 10.21, y = 20.95;
	return x * y;
}

int main()
{
	MyFunction();
	cout << MyFunction2() << endl;

	int Result = (MyFunction3() - 92) / 4;
	cout << Result << endl;

	cout << MyFunction4() << endl;

	int FlooredResult = floor(MyFunction4());

	cout << FlooredResult << endl;

	return 0;
}