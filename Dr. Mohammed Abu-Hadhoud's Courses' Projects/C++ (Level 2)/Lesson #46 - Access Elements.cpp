#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<short> Numbers{ 1, 2, 3, 4, 5 };

	for (short i = 0; i < 5; i++)
		cout << "[" << i << "]: " << Numbers[i] << endl;

	cout << endl << endl;

	for (short i = 0; i < 5; i++)
		cout << ".at(" << i << "): " << Numbers.at(i) << endl;

	cout << endl << endl;

	for (short Number : Numbers)
		cout << "for each: " << Number << endl;

	return 0;
}