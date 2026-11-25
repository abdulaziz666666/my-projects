#include <iostream>
using namespace std;

int main()
{
	void* ptr;

	int i = 10;
	float f = 0.19;

	ptr = &i;
	
	cout << ptr << endl;
	cout << *(static_cast<int*>(ptr)) << endl;

	ptr = &f;

	cout << ptr << endl;
	cout << *(static_cast<float*>(ptr)) << endl;

	return 0;
}