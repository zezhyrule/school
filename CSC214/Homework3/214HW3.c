// HEADER
//
// Resources: www.sanfoundry.com
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// PEP/9 SIMULATOR DOWNLOAD
//
// things to note: char array is a string
//				   already have program to convert binary to decimal
//				   pep/9 simulator should give same result

// function declarations
int incrementBinary(char* binary, int n);
int add(char* memory, char* reg, char* address, char* statusRegister);
int subtract(char* memory, char* reg, char* address, char* statusRegister);
int loadWord(char* memory, char* reg, char* address, char* statusRegister);
int storeWord(char* memory, char* reg, char* address, char* statusRegister);
int getSizeOfMemory(FILE *fp);
char* getInstruction(char* memory, char* programCounter);
long long toBin(long long decimalNum);
int toDec(char* binaryNum);
int power(int base, int exponent);
int addBinaryNumbers(char* num1, char* num2, char* result, char* statusRegister);

int main(char argc, char** argv)
{
	printf("\nBEGIN PROGRAM\n\n");
	
	// file i/o
	FILE *filePointer;
	char *filename = argv[1];

	filePointer = fopen(filename, "r");

	int memorySize = getSizeOfMemory(filePointer);
	int numOfBytes = memorySize / 8;

	//TEST print to see if bits are accurate
	printf("numberOfBits: %d\n\n", memorySize);
	printf("numberOfBytes: %d\n\n", numOfBytes);
	//end TEST

	//allocate memory
	char *memory = malloc(memorySize * sizeof(char) + (numOfBytes * 3));

	// Move fp to start
	fseek(filePointer, 0, SEEK_SET);

	// load memory
	int c;
	int i = 0;

	while(!feof(filePointer))
	{
		c = fgetc(filePointer);
		if (c == '0' || c == '1')
		{
			memory[i] = c;
			i++;
		}
	}

	fclose(filePointer);

	/////////////////////////////////////////////////
	// data structures initialized to all 0s
	char programCounter[20] = "0000000000000000";
	char statusRegister[8] = "0000";
	char accumulator[20] = "0000000000000000";
	char indexRegister[20] = "0000000000000000";
	char instructionSpecifier[12] = "00000000";
	char instructionRegister[28] = "000000000000000000000000";
	char stackPointer[20] = "0000000000000000";
	char word[20] = "0000000000000000";
	char address[20] = "0000000000000000";

	// register (0 is Accumulator, 1 is Index)
	char r;
	// addressing mode (001 is direct addressing)
	char aaa[4];

	//////////////////////////////////////////////////
	// start cycle
	int loop = 1;
	do
	{
		// Load instruction into instruction register
		strncpy(instructionRegister, &memory[toDec(programCounter)], 24);
		instructionRegister[24] = '\0';

		// Grab 8bit Instruction Specifier
		strncpy(instructionSpecifier, instructionRegister, 8);
		instructionSpecifier[8] = '\0';

		// Increment Program Counter by 1
		incrementBinary(programCounter, 1);

		/////////////////////////////////
		// Decode Instruction Specifier
		
		// Separate instruction specifier into nibbles
		char firstNibble[5];
		char secondNibble[5];

		strncpy(firstNibble, instructionSpecifier, 4);
		firstNibble[4] = '\0';

		strncpy(secondNibble, &instructionSpecifier[4], 4);
		secondNibble[4] = '\0';

		// Check if it's a unary instruction

		if (strcmp(firstNibble, "0000") == 0)
		{
			// Unary Instruction

			// Get Register
			r = secondNibble[3];

			// Decode instruction

			// Arithmetic Shift
			if (secondNibble[0] == '1' &&
				secondNibble[1] == '0' &&
				secondNibble[2] == '1')
			{
				// Perform Arithmetic shift left on r
				printf("ARITHEMTIC SHIFT LEFT\n");
			}
			else if (secondNibble[0] == '1' &&
					 secondNibble[1] == '1' &&
					 secondNibble[2] == '0')
			{
				// Perform Arithmetic Shift Right on r
				printf("ARITHEMTIC SHIFT RIGHT\n");
			}
		}
		else
		{
			// Non-unary

			// Get Register
			r = secondNibble[0];
			printf("register: %c\n", r);

			// Get addressing mode
			int i;
			for (i = 0; i < 3; i++)
			{
				aaa[i] = secondNibble[i+1];
			}
			aaa[3] = '\0';

			// Get word following instruction specifier
			strncpy(word, &instructionRegister[10], 18);
			word[18] = '\0';

			// Remove newline characters
			int j;
			for (i = 0, j = 0; i < 16; i++, j++)
			{
				if (word[j] == '1' || word[j] == '0')
				{
					address[i] = word[j];
				}
			}
			address[16] = '\0';

			// Decode instruction

			// Add/Subtract
			if (firstNibble[0] == '0')
			{
				if (firstNibble[1] == '1' &&
					firstNibble[2] == '1' &&
					firstNibble[3] == '0')
				{
					// Add to r
					if (r == '0')
					{
						//add(memory, accumulator, address, statusRegister);
						char addend[16];
						strncpy(addend, &memory[toDec(address)], 16);

						addBinaryNumbers(accumulator, addend,
										 accumulator, statusRegister);

					}
					else
					{
						char addend[16];
						strncpy(addend, &memory[toDec(address)], 16);
						addBinaryNumbers(indexRegister, addend,
										 indexRegister, statusRegister);
						//add(memory, indexRegister, address, statusRegister);
					}
					
				}
				else if (firstNibble[1] == '1' &&
						 firstNibble[2] == '1' &&
						 firstNibble[3] == '1')
				{
					// Subtract from r
					if (r == '0')
					{
						//subtract(memory, accumulator, address, statusRegister);
						char minuend[16];
						int i;
						strncpy(minuend, &memory[toDec(address)], 16);
						// convert to two's compliment
						printf("minuend: %s\n", minuend);
						for (i= 0; i < 16; i++)
						{
							if (minuend[i] == '0')
							{
								minuend[i] = '1';
							}
							else if (minuend[i] == '1')
							{
								minuend[i] = '0';
							}
						}
						incrementBinary(minuend, 1);
						printf("two's comp: %s\n", minuend);
						addBinaryNumbers(accumulator, minuend,
										 accumulator, statusRegister);
					}
					else
					{
						subtract(memory, indexRegister, address, statusRegister);
					}
				}
			}
			// Load/Store
			else
			{
				if (firstNibble[1] == '1' &&
					firstNibble[2] == '0' &&
					firstNibble[3] == '0')
				{
					// Load word into r from memory
					if (r == '0')
					{
						loadWord(memory, accumulator, address, statusRegister);
					}
					else
					{
						loadWord(memory, indexRegister, address, statusRegister);
					}
				}
				else if (firstNibble[1] == '1' &&
						 firstNibble[2] == '1' &&
						 firstNibble[3] == '0')
				{
					// Store word r to memory
					if (r == '0')
					{
						storeWord(memory, accumulator, address, statusRegister);
					}
					else
					{
						storeWord(memory, indexRegister, address, statusRegister);
					}
				}
			}


			// Increment Program Counter by 2
			incrementBinary(programCounter, 2);
		}

		printf("Instruction Number %d\n", loop);
		printf("Status (NZVC):  %s\n", statusRegister);
		printf("Program Counter: %s\n", programCounter);
		printf("Instruction: %s\n", instructionRegister);
		printf("Accumulator: %s\n", accumulator);
		printf("Index: %s\n", indexRegister);
		printf("Stack Pointer: %s\n", stackPointer);
		printf("----------------------------------\n");
		loop++;
	}
	while(strcmp(instructionSpecifier, "00000000") != 0);

	free(memory);

	return 0;
} // end main

int incrementBinary(char* binary, int n)
{
	char temp[4];
	if (n == 1)
	{
		addBinaryNumbers(binary, "0000000000000001", binary, temp);
	}
	if (n == 2)
	{
		addBinaryNumbers(binary, "0000000000000010", binary, temp);
	}

	return 0;
} // end incrementBinary

int add(char* memory, char* reg, char* address, char* statusRegister)
{
	char addend[16];
	strncpy(addend, &memory[toDec(address)], 16);

	addBinaryNumbers(reg, addend, reg, statusRegister);

	return 0;
} // end add

int subtract(char* memory, char* reg, char* address, char* statusRegister)
{
	char minuend[16];
	int i;
	strncpy(minuend, &memory[toDec(address)], 16);
	// convert to two's compliment
	printf("minuend: %s\n", minuend);
	for (i= 0; i < 16; i++)
	{
		if (minuend[i] == '0')
		{
			minuend[i] = '1';
		}
		else if (minuend[i] == '1')
		{
			minuend[i] = '0';
		}
	}
	incrementBinary(minuend, 1);
	printf("two's comp: %s\n", minuend);
	addBinaryNumbers(reg, minuend, reg, statusRegister);

	return 0;
} // end subtract

int loadWord(char* memory, char* reg, char* address, char* statusRegister)
{
	char word[17];

	strncpy(word, &memory[toDec(address)], 16);
	word[16] = '\0';
	printf("load word: %s\n", word);

	strncpy(reg, word, 16);

	return 0;
} // end loadWord

int storeWord(char* memory, char* reg, char* address, char* statusRegister)
{
	char word[17];
	strncpy(word, reg, 16);
	word[16] = '\0';
	printf("store word: %s\n", word);
	strncpy(&memory[toDec(address)], word, 16);

	return 0;
} // end storeWord

int getSizeOfMemory(FILE *filePointer)
{
// function header
//
	char temp; //temporary char variable
	int numOfBits = 0;

	while(!feof(filePointer))
	{
		temp = fgetc(filePointer);
		if (temp == '0' || temp == '1')
		{
			numOfBits++;
		}
	}

	return numOfBits;
} // end getSizeOfMemory

long long toBin(long long decimalNum)
{
	int remainder;
	long long binary = 0;
	long long i = 1;

	while (decimalNum != 0)
	{
		remainder = decimalNum % 2;
		decimalNum = decimalNum / 2;
		binary = binary + (remainder * i);
		i = i*10;
	}

	return binary;
} // end toBin

int toDec(char* binaryNum)
{
	int lengthOfString = strlen(binaryNum) - 1;
	int i, j = 0;
	int bit = 0;
	int bitValue = 0;
	int decimalNum = 0;

	for (i = 0, j = lengthOfString; i < lengthOfString, j >= 0; i++, j--)
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

int addBinaryNumbers(char* num1, char* num2, char* result, char* statusRegister)
{
/*
 * Function Header
 *
 */
	char *ptr1;
	char *ptr2;

	int length = strlen(num1);
	long long binary1 = toBin(strtoll(num1, &ptr1, 2));
	long long binary2 = toBin(strtoll(num2, &ptr2, 2));

	int i = 0;
	int remainder = 0;
	int sum[25];

	while (binary1 != 0 || binary2 != 0)
	{
		sum[i++] =(binary1 % 10 + binary2 % 10 + remainder) % 2;
		remainder =(binary1 % 10 + binary2 % 10 + remainder) / 2;
		binary1 = binary1 / 10;
		binary2 = binary2 / 10;
	}

	if (remainder != 0)
	{
		sum[i++] = remainder;

		// Set carry bit
		statusRegister[3] = '1';
	}

	--i;


	int emptyBits = (length - 1) - i;

	while (i >= 0)
	{
		result[(length - 1) - i] = sum[i] + '0';
		--i;
	}

	while (emptyBits >= 0)
	{
		--emptyBits;
		if (emptyBits >= 0)
		{
			result[emptyBits] = '0';
		}
	}

	// Check zero flag
	int zero = 1;
	int loop = 0;
	for (loop = 0; loop < strlen(result); loop++)
	{
		if (result[loop] != '0')
		{
			zero = 0; // non-zero bit
		}
	}

	if (zero == 1)
	{
		// Set zero flag
		statusRegister[1] = '1';
	}

	// Check overflow
	int overflow = 0;

	if (num1[0] == '1' && num2[0] == '1')
	{
		if (result[0] == '0')
		{
			overflow = 1;
		}
	}
	else if (num1[0] == '0' && num2[0] == '0')
	{
		if (result[0] == '1')
		{
			overflow = 1;
		}
	}

	if (overflow == 1)
	{
		// Set overflow flag
		statusRegister[2] = '1';
	}

	// Check negative flag
	if (result[0] == '1')
	{
		// Set negative flag
		statusRegister[0] = '1';
	}
	else
	{
		statusRegister[0] = '0';
	}

	return 0;
} // end addBinaryNumbers
