#include <iostream>
using namespace std;

int main()
{
	int Grade = 50;
	string Result = "";
	
	Result = (Grade >= 50) ? "Pass" : "Fail";

	cout << Result << endl;

	return 0;
}