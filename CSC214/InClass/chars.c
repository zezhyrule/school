#include<stdio.h> // library needed for simple I/O

char ch;
int j;

void customFunction(); // function prototype declaration

int main()
{
	ch = '!';
	j = 12;

	printf(" integer: %d \n character: %c", j, ch);
	customFunction();
	printf("\n integer: %d \n character: %c", j, ch);

	return 0;
}

void customFunction()
{
	ch = 'Z';
	j = 73;
}
