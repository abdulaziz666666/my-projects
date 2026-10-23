#include <iostream>
using namespace std;

int ReadNumber()
{
	unsigned Num;

	cout << "Please enter a number to count from it downward to 1: ";
	cin >> Num;

	return Num;
}

void CountFromNumTo1(unsigned Num)
{
	//for (int i = Num; i >= 1; i--)
	//{
	//	cout << i << endl;
	//}

	int i = Num;

	while (i >= 1)
	{
		cout << i << endl;
		i--;
	}
}

int main()
{
	unsigned Num = ReadNumber();
	CountFromNumTo1(Num);

	return 0;
}