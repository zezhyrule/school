#include<stdio.h>

const int ARRAY_SIZE = 4;

int main()
{
	int myarray[ARRAY_SIZE];

	int i;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		myarray[i] = i + 1;
	}

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("\n%d", myarray[i]);
	}

	return 0;
}
