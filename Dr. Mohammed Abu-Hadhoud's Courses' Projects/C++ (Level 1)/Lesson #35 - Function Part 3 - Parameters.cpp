#include <iostream>
using namespace std;

int MySumFunction(int Num1, int Num2)
{
	return Num1 + Num2;
}

int main()
{
	int Num1, Num2;

	cin >> Num1;
	cin >> Num2;

	cout << MySumFunction(Num1, Num2) << endl;

	return 0;
}