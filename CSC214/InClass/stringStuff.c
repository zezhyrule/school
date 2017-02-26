#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
	const int BUFFER = 50;
	char str[BUFFER];      // an array

	gets(str); // read whole string from console until
			   // newline and store inside array
			   
	printf("\n\n%s\n\n", str);

	int i = 0;
	for (i = 0; i < BUFFER; i++)
	{
		printf("%c", str[i]);
		// this prints out the char array along with
		// all the junk data following it up until BUFFER
	}
	printf("\n\n");

	int size = strlen(str); // returns pos of null character

	for (i = 0; i < size; i++)
	{
		printf("%c", str[i]);
		// now it'll only print out the desired portion of the array
	}
	printf("\n\n");

	return 0;
}
