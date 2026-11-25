#include <iostream>
using namespace std;
int main() {
	int n, sum = 0;
	cout << "Enter a Positive Number: ";
	cin >> n;
	cout << "Even numbers from 1 to " << n << endl;
	for (int counter = 1; counter <= n; counter++)
	{
		//check if counter is divisible by 2
		if (counter % 2 == 0) {
			cout << counter << " ";
			//counter is even number, add it to sum
			sum += counter;
		}
	}

	cout << "\nSum of all Even numbers is " << sum;
	return 0;
}
