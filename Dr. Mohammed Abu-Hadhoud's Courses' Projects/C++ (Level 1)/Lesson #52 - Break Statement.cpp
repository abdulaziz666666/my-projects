#include <iostream>
using namespace std;

void Example1()
{
	for (int i = 1; i <= 10; i++)
	{
		if (i == 3)
		{
			break;
		}

		cout << i << endl;
	}
}



int main()
{
	Example1();
	return 0;
}