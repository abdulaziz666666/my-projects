#include <iostream>
using namespace std;

void Example1()
{
	int x = 10;

	if (x >= 5 || x == 20)
	{
		cout << "X is 5 or bigger or is 20." << endl;
	}

	cout << "That string will be printed anyway." << endl;
}

void Example2()
{
	int y = -9;

	if (y >= 0)
	{
		cout << "Y is 0 or positive." << endl;
	}
	else
	{
		cout << "Y is negative." << endl;
	}
	cout << "That string will be printed anyway." << endl;

}

void Example3()
{
	int Num;

	cout << "Please enter a number: ";
	cin >> Num;

	if (Num > 5)
	{
		cout << "Yes, the number is greater than 5." << endl;
	}
	else
	{
		cout << "No, the number is less than 5." << endl;
	}

	cout << "That is another string that doesn\'t have anything with the if statement." << endl;
}

int main()
{
	// the if statement has a body holds the code. Furthermore, the else statement also has
	// that body, so they either called if statement body or else statement body.
	Example3(); 
	return 0;
}