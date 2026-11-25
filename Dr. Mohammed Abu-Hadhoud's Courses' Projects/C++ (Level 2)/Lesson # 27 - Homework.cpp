#include <iostream>
using namespace std;

void FillMultiplication2DArray(int Arr[10][10])
{
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
			Arr[i - 1][j - 1] = i * j; 
	}
}

void PrintMultiplication2DArray(int Arr[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			printf("%0*d ", 2, Arr[i][j]);

		cout << endl;
	}
}

int main()
{
	int MultiplicationArray[10][10];

	FillMultiplication2DArray(MultiplicationArray);
	PrintMultiplication2DArray(MultiplicationArray);

	return 0;
}