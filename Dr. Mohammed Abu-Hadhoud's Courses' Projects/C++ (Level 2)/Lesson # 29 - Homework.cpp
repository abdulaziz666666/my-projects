#include <iostream>
#include <vector>
using namespace std;

bool AskUserToContinueReading()
{
	//static char EnterMoreNumbers = 'Y'; // so it doesn't create it numerous times.
	char EnterMoreNumbers = 'Y'; // as i'm not sure, i removed it.

	cout << "\nDo you want to continue (y/n) ? : ";
	cin >> EnterMoreNumbers;

	return (EnterMoreNumbers == 'Y' || EnterMoreNumbers == 'y');
}

void ReadNumbers(vector <int>& vNumbers)
{
	int Num = 0;

	do
	{
		cout << "Please enter a number: ";
		cin >> Num;

		vNumbers.push_back(Num);

	} while (AskUserToContinueReading());
}

//void PrintNumbers(vector <int> vNumbers)
//void PrintVectorNumbers(vector <int> vNumbers)
void PrintVectorNumbers(vector <int> &vNumbers)
{
	cout << "\nVector Numbers:\n\n";

	for (int& Number : vNumbers)
	{
		cout << Number << endl;
	}
}

int main()
{
	vector <int> vNumbers;

	ReadNumbers(vNumbers);
	PrintVectorNumbers(vNumbers);

	return 0;
}