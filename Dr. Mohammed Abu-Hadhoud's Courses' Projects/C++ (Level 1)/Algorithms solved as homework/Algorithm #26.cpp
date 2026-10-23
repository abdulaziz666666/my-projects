#include <iostream>
using namespace std;

int ReadNumber()
{
	unsigned Num;

	cout << "Please enter a number to count from 1 to it: ";
	cin >> Num;

	return Num;
}

void CountFrom1ToNum(unsigned Num)
{
	//for (int i = 1; i <= Num; i++)
	//{
	//	cout << i << endl;
	//}
	unsigned i = 1;

	while (i <= Num)
	{
		cout << i << endl;
		i++;
	}
}

int main()
{
	unsigned Num = ReadNumber();
	CountFrom1ToNum(Num);

	return 0;
}