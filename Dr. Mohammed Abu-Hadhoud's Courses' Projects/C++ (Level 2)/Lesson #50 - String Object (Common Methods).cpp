#include <iostream>
#include <string>
#include <iterator>
using namespace std;

int main()
{
	string s = "Hello, My Name is Abdulaziz Al-Odail. I am really passionate.";

	cout << s.length() << endl;
	cout << s.at(3) << endl;

	cout << "application for at():\n\n";

	for (short i = 0; i < s.length(); i++)
	{
		cout << s.at(i);
	}
	cout << "\n\n";

	s.append(" @Xz3tR6");
	cout << s << endl;

	s.insert(28, "Nasser ");
	cout << s << endl;

	cout << s.substr(5, 22) << endl; // 1: start from where, 2: how many charachters to select?

	s.push_back('P');
	cout << s << endl;
	s.pop_back();
	cout << s << endl;

	cout << s.find("@Xz3tR6") << endl;
	cout << s.find("something") << endl;
	
	// sometimes the chosen substr is not in the string
	// so we need to ensure that the value of find()
	// is a valid one.
	if (s.find("something") == s.npos) // s.npos = no-position
		cout << "It is NOT there\n";
	else 
		cout << "It is there\n";

	s.clear();

	cout << "after clearing: " << s << endl;

	return 0;
}