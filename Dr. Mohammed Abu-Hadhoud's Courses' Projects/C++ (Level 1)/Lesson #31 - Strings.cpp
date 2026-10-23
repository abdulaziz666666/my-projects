#include <iostream>
#include <string>
using namespace std;

int main()
{
	string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << "Alphabet Length: " << Alphabet.length() << endl;
	cout << "The Third Character is " << Alphabet[2] << endl;

	string S1 = "10", S2 = "20";
	string S3 = S1 + S2; // Concatenation
	cout << S3 << endl;

	int Sum = stoi(S1) + stoi(S2);
	cout << Sum << endl;


	string FullName;
	//cin >> FullName; // It reads the first word only.
	getline(cin, FullName);
	cout << FullName;

	return 0;
}