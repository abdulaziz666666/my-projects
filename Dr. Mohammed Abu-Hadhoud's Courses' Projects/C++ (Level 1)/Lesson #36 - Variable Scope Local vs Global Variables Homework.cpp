#include <iostream>
using namespace std;

string s = "global", s2;

void func()
{
	string s = "inside func()";
	s2 = "s2 changed in func";
	cout << s << endl;
}

int main()
{

	string s = "inside main()";
	cout << s << endl;
	cout << ::s << endl;

	s2 = "s2 changed in main";
	cout << s2 << endl;
	return 0;
}