#include <iostream>
using namespace std;

int main()
{
	char Name[] = "Abdulaziz Al-Odail";
	char CollageName[] = "CSSIT";

	printf("Hi %s, welcome to %s! \n", Name, CollageName);

	char Charachter = 'c';

	printf("trying to set the width a certain letter: %*c \n", 1, Charachter);
	printf("trying to set the width a certain letter: %*c \n", 4, Charachter);
	printf("trying to set the width a certain letter: %*c \n", 10, Charachter);

	return 0;
}