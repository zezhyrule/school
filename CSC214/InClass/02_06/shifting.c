#include<stdio.h>

// SHIFT

int main(int argc, char **argv)
{

	char a,b,c;

	a = -39;
	b = 100;

	c = a << 1;

	printf("\n-39 << 1 = %d\n", c); // -78

	c = b << 1;

	printf("\n100 << 1 = %d\n", c);

	c = b >> 1;

	printf("\n100 >> 1 = %d\n", c);
	
	return 0;
}
