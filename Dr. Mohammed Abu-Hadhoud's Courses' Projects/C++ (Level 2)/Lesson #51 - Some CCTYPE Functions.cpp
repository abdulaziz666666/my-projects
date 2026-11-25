#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char a;

	a = toupper('z');
	cout << a << endl;

	a = tolower('Z');
	cout << a << endl;

	cout << "is lower: " << islower(a) << endl;
	cout << "is upper " << isupper(a) << endl;
	cout << "is upper " << isupper('g') << endl;

	cout << "isdigit: " << isdigit('8') << endl;
	cout << "isdigit: " << isdigit('x') << endl;

	cout << "is punct: " << ispunct('x') << endl;
	cout << "is punct: " << ispunct('.') << endl;
	cout << "is punct: " << ispunct('=') << endl;

	return 0;
}