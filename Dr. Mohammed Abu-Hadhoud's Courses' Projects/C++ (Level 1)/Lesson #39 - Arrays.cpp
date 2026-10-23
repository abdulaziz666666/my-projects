#include <iostream>
using namespace std;

int main()
{
	int Nums[5] = { 23, 652, 1, 965, 3 };

	cout << Nums[0] << endl;
	cout << Nums[1] << endl;
	cout << Nums[2] << endl;
	cout << Nums[3] << endl;
	cout << Nums[4] << endl;

	cout << endl;

	cout << Nums[0] * 9 << endl;
	cout << Nums[0] / Nums[4] * Nums[3] - 49 << endl;

	cout << endl;

	float x[2];

	x[0] = -1.15;
	x[1] = 9.051;

	cout << x[0] + x[1] << endl;

	return 0;
}