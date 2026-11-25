#include <iostream>
using namespace std;

int main()
{
	int Page = 4, TotalPages = 181;

	printf("Page %d of %d\n", Page, TotalPages);

	printf("Current Page is %0*d \n", 1, Page);
	printf("Current Page is %0*d \n", 2, Page);
	printf("Current Page is %0*d \n", 3, Page);

	int Num1 = 345, Num2 = 12;
	int Total = Num1 + Num2;
	printf("%d + %d = %d\n", Num1, Num2, Total);

	printf(" %0*d\n", 8, Num1);
	printf(" %0*d\t+\n", 8, Num2);
	printf("---------------\n");
	printf(" %0*d", 8, Total);

	return 0;
}