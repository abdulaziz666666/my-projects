#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> Nums{ 1,2,3,4,5 };


	try
	{
		cout << Nums.at(10) << endl;
	}
	catch (...)
	{
		cout << "You tried to reach an index that is out of range.\n";
	}

	return 0;
}