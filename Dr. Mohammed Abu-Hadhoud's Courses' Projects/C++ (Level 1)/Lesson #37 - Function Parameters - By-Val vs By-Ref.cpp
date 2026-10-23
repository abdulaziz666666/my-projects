#include <iostream>
using namespace std;

void MyFunction(int &Num)
{
	Num = 1000;
	cout << "Inside the function = " << Num << endl;
}

int main()
{
	int Num = 3;
	//MyFunction(Num);
	//cout << "After the change = " << Num << endl;

	cout << Num << endl;
	cout << &Num << endl;

	return 0;
}