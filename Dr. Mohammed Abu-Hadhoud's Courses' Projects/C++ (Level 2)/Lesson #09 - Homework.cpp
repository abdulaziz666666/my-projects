#include <iostream>
using namespace std;

int main()
{
	int Number = 0;
	string Result = "";

	//(Number >= 0) ? cout << "Positive\n" : cout << "Negative\n";
	//(Number == 0) ? cout << "Zero\n" : (Number > 0) ? cout << "Positive\n" : cout << "Negative\n";

	Result = (Number > 0) ? "Positive" : "Negative"; // first one
	Result = (Number == 0) ? "Zero" : (Number > 0) ? "Positive" : "Negative"; // second one

	cout << "Numebr is " << Result << endl;

	return 0;
}