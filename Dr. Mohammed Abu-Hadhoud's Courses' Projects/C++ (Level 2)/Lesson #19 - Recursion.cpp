#include <iostream>
using namespace std;

void PrintNumbers(int From, int To)
{
	if (From <= To)
	{
		cout << From << endl;
		PrintNumbers(From + 1, To);
	}
}

int main()
{

	PrintNumbers(1, 10);

	return 0;
}