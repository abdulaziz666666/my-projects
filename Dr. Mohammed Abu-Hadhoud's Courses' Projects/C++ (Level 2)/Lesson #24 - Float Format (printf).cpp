#include <iostream>
using namespace std;

int main()
{

	float PI = 3.14159;

	printf("pi = %.*f \n", 0, PI);
	printf("pi = %.*f \n", 1, PI);
	printf("pi = %.*f \n", 2, PI);
	
	printf("a = %.3f b = %.1f \n", 2.824731, 0.42112);

	double x = 1.523;

	printf("a = %.2f b = %.7f \n", x, x);

	return 0;
}