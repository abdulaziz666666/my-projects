#include <iostream>
using namespace std;

void PrintName(string Name)
{
	cout << Name << endl;
}

int main()
{
	string Name;

	cin >> Name;

	PrintName(Name);

	return 0;
}