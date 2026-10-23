#include <iostream>
#include <string>
using namespace std;

int main()
{
	string Phrase, TextNum1, TextNum2;

	cout << "Please enter a phrase:" << endl;
	getline(cin, Phrase);

	cout << endl;
	
	cout << "Please enter a number:" << endl;
	cin >> TextNum1;

	cout << endl;
	
	cout << "Please enter another number:" << endl;
	cin >> TextNum2;

	cout << "*************************" << endl;

	cout << "The length of the phrase was " << Phrase.length() << endl;
	cout << "Characters at 0, 2, 4, 7 are: ";
	cout << Phrase[0] << " ";
	cout << Phrase[2] << " ";
	cout << Phrase[4] << " ";
	cout << Phrase[7] << endl;

	cout << "If we concatenate the two numbers, they will become " << TextNum1 + TextNum2 << endl;

	int Result = stoi(TextNum1) * stoi(TextNum2);
	cout << TextNum1 << " * " << TextNum2 << " = " << Result << endl;

	return 0;
}