#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	string Name = "Abdulaziz Al-Odail";
	string Spec = "CS";
	
	cout << "----------------------------------------  \n";
	cout << "          Name           |     Spec     | \n";
	cout << "----------------------------------------  \n";
	cout << setw(24) << Name << " | " << setw(12) << Spec << " |" << endl;
	cout << "----------------------------------------  \n";


	return 0;
}