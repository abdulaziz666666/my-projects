#include <iostream>
using namespace std;

void Example1()
{
	for (int i = 1; i <= 5; i++)
	{
		if (i == 3)
		{
			continue;
		}

		cout << i << endl;
	}
}

int main()
{
	Example1();
	return 0;
}