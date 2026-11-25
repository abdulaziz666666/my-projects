#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> Nums = { 1, 2, 3, 4, 5 };

	cout << "Fastest:\n";

	for (const int& n : Nums) 
	{
		cout << n << " ";
	}

	cout << "\n\nLess speed - Ideal for configuring:\n";

	for (int& n : Nums)
	{
		n *= n;
		cout << n << " ";
	}

	Nums[0] = 101;
	Nums.at(3) = 999;

	cout << "\n\nBad - Don't see it when iterating numerous structs:\n";
	for (int n : Nums)
	{
		cout << n << " ";
	}

	return 0;
}