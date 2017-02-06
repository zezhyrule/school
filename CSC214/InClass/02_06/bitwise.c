#include<stdio.h>

// BITWISE OPERATIONS

int main(int argc, char **argv)
{
	char a,b,c;

	a = 50;
	b = 40;

	// double ampersand is boolean comparison
	if (a == 50 && b == 40)
	{
		printf("\na is 50 and b is 40\n");
	}

	// single ampersand is bitwise operation
	
	c = a & b; // 32
	printf("\na & b = %d", c);

	c = a | b; // 58
	printf("\na | b = %d", c);
	
	c = a ^ b; // 26
	printf("\na ^ b = %d", c);


	return 0;
}
