#include <iostream>
using namespace std;

void PrintAlphabet()
{
	for (int i = 65; i <= 90; i++)
		cout << char(i) << endl; // also, it can be done through (char)i
}

int main()
{
	PrintAlphabet();
	return 0;
}