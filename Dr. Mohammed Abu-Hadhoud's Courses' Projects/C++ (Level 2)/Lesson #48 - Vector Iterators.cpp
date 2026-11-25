#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<short> Nums{ 1,2,3,4,5 };

	vector<short>::iterator Iter;

	for (Iter = Nums.begin(); Iter != Nums.end(); Iter++)
	{
		cout << *Iter << " ";
	}

	return 0;
}