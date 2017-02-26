//Homework 2
//Charles Davis

#include<stdio.h>
#include<string.h>

int convertToDecimal(char* binaryNum, char* signFlag);
int power(int base, int exponent);

int main(int argc, char** argv)
{
	if (argc != 3) // ensure correct number of arguments
	{
		printf("\nusage: %s <signflag> <binarynumber>", argv[0]);
		printf("\n\nsignflag: -U, unsigned\n          -S, signed");
		printf("\n\nbinarynumber: 8bit binary number\n\n");
	}
	else
	{
		char* signFlag = *(argv + 1);
		char* binaryNum = *(argv + 2);
		int decimalNum;

		decimalNum = convertToDecimal(binaryNum, signFlag);

		printf("\nbinary: %s\n", binaryNum);
		printf("\ndecimal: %d\n", decimalNum);
	} // end if

	return 0;
} // end main

int convertToDecimal(char* binaryNum, char* signFlag)
{
	int i, j = 0;
	int bit = 0;
	int bitValue = 0;
	int decimalNum = 0;
	char signedDecimalNum = 0;

	if (strcmp(signFlag, "-S") == 0) // number is signed
	{
		for (i = 0, j = 7; i < 7, j >= 0; i++, j--)
		{
			bit = *(binaryNum + i) - '0'; // take away '0' (48 in ASCII)
										  // to get represented int
			bitValue = bit * power(2, j);
			
			signedDecimalNum += bitValue;
		}

		return signedDecimalNum;
	} // end if

	// else, number is unsigned
	for (i = 0, j = 7; i < 7, j >= 0; i++, j--)
	{
		bit = *(binaryNum + i) - '0'; // take away '0' (48 in ASCII)
									  // to get represented int
		bitValue = bit * power(2, j);
		
		decimalNum += bitValue;
	}

	return decimalNum;
} // end convertToDecimal

int power(int base, int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}

	if (exponent == 1)
	{
		return base;
	}

	return base * power(base, exponent - 1);
} // end power
