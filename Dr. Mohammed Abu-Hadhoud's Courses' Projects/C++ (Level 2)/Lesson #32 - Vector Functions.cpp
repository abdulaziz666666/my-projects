#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> vNumbers;

	for (int i = 1; i <= 5; i++)
		vNumbers.push_back(i);

	cout << "First Element: " << vNumbers.front() << endl;
	cout << "Last Element: " << vNumbers.back() << endl;

	cout << "Size: " << vNumbers.size() << endl;

	cout << "Capacity: " << vNumbers.capacity() << endl;

	cout << "Empty? : " << vNumbers.empty() << endl;
	
	vNumbers.clear();

	cout << "Empty? : " << vNumbers.empty() << endl;

	return 0;
}