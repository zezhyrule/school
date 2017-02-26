#include<stdio.h>

// OVERFLOW

int main(int argc, char **argv)
{
	printf("\nSigned:\n");

	char val = 126;

	printf("\n%d\n", val);
	val++;
	printf("\n%d\n", val); // 127
	val++;
	printf("\n%d\n", val); // -128
	val++;
	printf("\n%d\n", val); // -127

	printf("\nUnsigned:\n");

	unsigned char val = 254;

	printf("\n%d\n", val);
	val++;
	printf("\n%d\n", val); // 255
	val++;
	printf("\n%d\n", val); // 0
	val++;
	printf("\n%d\n", val); // 1

	return 0;
}
