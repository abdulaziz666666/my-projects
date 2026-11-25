#include <iostream>
using namespace std;

int main()
{
	int Arr[4] = { 5, 10, 15, 20 };
	int* ptr = Arr;
	
	cout << ptr << "\t--->\t" << *ptr << endl;
	cout << ptr + 1 << "\t--->\t" << *(ptr + 1) << endl;
	cout << ptr + 2 << "\t--->\t" << *(ptr + 2) << endl;
	cout << ptr + 3 << "\t--->\t" << *(ptr + 3) << endl;

	cout << endl;

	for (int i = 0; i < 4; i++)
		cout << ptr + i << "\t--->\t" << *(ptr + i) << endl;

	return 0;
}