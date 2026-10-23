#include <iostream>
using namespace std;

void PrintNumIndexInArray(int Arr[10], int Target)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "We are at the iteration number " << i << endl;

		if (Arr[i] == Target)
		{
			cout << endl << Target << " found at index of " << i << endl << endl;
			break; // try to comment it and see the difference
		}
	}
}

int main()
{
	int Arr[10] = { 10, 20, 44, 55, 33, 22, 99, 88, 99, 100 };

	PrintNumIndexInArray(Arr, 20);

	return 0;
}