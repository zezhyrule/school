// PEP/9 SIMULATOR
// Charles Davis
//
// Resources: www.sanfoundry.com
//			  computersystemsbook.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// Function Declarations
int incrementBinary(char* binary, int n);
int add(char* memory, char* reg, char* address, char* statusRegister);
int subtract(char* memory, char* reg, char* address, char* statusRegister);
int loadWord(char* memory, char* reg, char* address, char* statusRegister);
int storeWord(char* memory, char* reg, char* address, char* statusRegister);
int arithmeticShift(char direction, char* reg, char* statusRegister);
int getSizeOfMemory(FILE *fp);
long long toBin(long long decimalNum);
int getLocation(char* binaryNum);
int power(int base, int exponent);
int addBinaryNumbers(char* num1, char* num2, char* result, char* statusRegister);

int main(char argc, char** argv)
{
	// File i/o
	FILE *filePointer;
	char *filename = argv[1];

	filePointer = fopen(filename, "r");

	int memorySize = getSizeOfMemory(filePointer);
	int numOfBytes = memorySize / 8;

	// Allocate memory
	char *memory = malloc(memorySize * sizeof(char) + (numOfBytes * 3));

	// Move file pointer back to start
	fseek(filePointer, 0, SEEK_SET);

	// Load memory into array
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
	// Initialize data structures
	char programCounter[17] = "0000000000000000";
	char statusRegister[5] = "0000";
	char accumulator[17] = "0000000000000000";
	char indexRegister[17] = "0000000000000000";
	char instructionSpecifier[9] = "00000000";
	char instructionRegister[25] = "000000000000000000000000";
	char stackPointer[17] = "0000000000000000";
	char word[17] = "0000000000000000";
	char address[17] = "0000000000000000";

	// Register (0 is Accumulator, 1 is Index)
	char r;
	// Addressing mode (001 is direct addressing)
	char aaa[4];

	//////////////////////////////////////////////////
	// Start cycle
	int loop = 1;
	do
	{
		/////////////////////////////////////////////
		// Load instruction into instruction register
		strncpy(instructionRegister, &memory[getLocation(programCounter)], 24);
		instructionRegister[24] = '\0';

		// Grab 8bit Instruction Specifier
		strncpy(instructionSpecifier, instructionRegister, 8);
		instructionSpecifier[8] = '\0';

		// Increment Program Counter by 1
		incrementBinary(programCounter, 1);

		/////////////////////////////////////////////
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
				if (r == '0')
				{
					arithmeticShift('L', accumulator, statusRegister);
				}
				else
				{
					arithmeticShift('L', indexRegister, statusRegister);
				}
			}
			else if (secondNibble[0] == '1' &&
					 secondNibble[1] == '1' &&
					 secondNibble[2] == '0')
			{
				// Perform Arithmetic Shift Right on r
				if (r == '0')
				{
					arithmeticShift('R', accumulator, statusRegister);
				}
				else
				{
					arithmeticShift('R', indexRegister, statusRegister);
				}
			}
		}
		else
		{
			// Non-unary

			// Get Register
			r = secondNibble[0];

			// Get addressing mode
			int i;
			for (i = 0; i < 3; i++)
			{
				aaa[i] = secondNibble[i+1];
			}
			aaa[3] = '\0';

			// Get word following instruction specifier
			strncpy(address, &instructionRegister[8], 16);
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
						add(memory, accumulator, address, statusRegister);
					}
					else
					{
						add(memory, indexRegister, address, statusRegister);
					}
					
				}
				else if (firstNibble[1] == '1' &&
						 firstNibble[2] == '1' &&
						 firstNibble[3] == '1')
				{
					// Subtract from r
					if (r == '0')
					{
						subtract(memory, accumulator, address, statusRegister);
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

		// Print current status
		printf("\n");
		printf("Instruction Number %d\n", loop);
		printf("Status (NZVC):  %s\n", statusRegister);
		printf("Program Counter: %s\n", programCounter);
		printf("Instruction: %s\n", instructionRegister);
		printf("Accumulator: %s\n", accumulator);
		printf("Index: %.16s\n", indexRegister);
		printf("Stack Pointer: %s\n", stackPointer);
		printf("----------------------------------\n");
		loop++;
	}
	while(strcmp(instructionSpecifier, "00000000") != 0);
	
	// Print memory dump
	printf("\n");
	int newline = 0;
	for (i = 0; i < memorySize; i++)
	{
		printf("%c", memory[i]);

		newline++;

		if (newline == 8)
		{
			printf("\n");
			newline = 0;
		}
	}
	printf("\n");

	free(memory);

	return 0;
} // end main

int incrementBinary(char* binary, int n)
{
	char temp[5];
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
	char addend[17];
	memset(addend, '\0', sizeof(addend));
	strncpy(addend, &memory[getLocation(address)], 16);
	addend[16] = '\0';

	addBinaryNumbers(reg, addend, reg, statusRegister);

	reg[16] = '\0';

	return 0;
} // end add

int subtract(char* memory, char* reg, char* address, char* statusRegister)
{
	char minuend[17];
	int i;
	memset(minuend, '\0', sizeof(minuend));
	strncpy(minuend, &memory[getLocation(address)], 16);
	minuend[16] = '\0';

	// convert to two's compliment
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
	addBinaryNumbers(reg, minuend, reg, statusRegister);

	reg[16] = '\0';

	return 0;
} // end subtract

int loadWord(char* memory, char* reg, char* address, char* statusRegister)
{
	strncpy(reg, &memory[getLocation(address)], 16);
	reg[16] = '\0';

	// Check negative flag
	if (reg[0] == '1')
	{
		// Set negative flag
		statusRegister[0] = '1';
	}
	else
	{
		statusRegister[0] = '0';
	}
	
	// Check zero flag
	int zero = 1;
	int loop = 0;
	for (loop = 0; loop < strlen(reg); loop++)
	{
		if (reg[loop] != '0')
		{
			zero = 0; // non-zero bit
		}
	}
	if (zero == 1)
	{
		// Set zero flag
		statusRegister[1] = '1';
	}
	else
	{
		statusRegister[1] = '0';
	}

	return 0;
} // end loadWord

int storeWord(char* memory, char* reg, char* address, char* statusRegister)
{
	strncpy(&memory[getLocation(address)], reg, 16);

	// Check negative flag
	if (reg[0] == '1')
	{
		// Set negative flag
		statusRegister[0] = '1';
	}
	else
	{
		statusRegister[0] = '0';
	}
	
	// Check zero flag
	int zero = 1;
	int loop = 0;
	for (loop = 0; loop < strlen(reg); loop++)
	{
		if (reg[loop] != '0')
		{
			zero = 0; // non-zero bit
		}
	}
	if (zero == 1)
	{
		// Set zero flag
		statusRegister[1] = '1';
	}
	else
	{
		statusRegister[1] = '0';
	}

	return 0;
} // end storeWord

int arithmeticShift(char direction, char* reg, char* statusRegister)
{
	char temp[17];
	int len = strlen(reg);
	int i = 0;

	memset(temp, '\0', sizeof(temp));
	strncpy(temp, reg, 16);
	temp[16] = '\0';
	
	if (direction == 'L')
	{
		for (i = 0; i < len - 1; i++)
		{
			reg[i] = temp[i+1];
		}
		reg[len - 1] = '0';
	}
	else if (direction == 'R')
	{
		char mostSig = reg[0];
		for (i = len - 1; i > 0; i--)
		{
			reg[i] = temp[i-1];
		}
		reg[0] = mostSig;
	}

	return 0;
} // end arithmeticShift

int getSizeOfMemory(FILE *filePointer)
{
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

int getLocation(char* binaryNum)
{
	int lengthOfString = strlen(binaryNum) - 1;
	int i, j = 0;
	int bit = 0;
	int bitValue = 0;
	int decimalNum = 0;
	int bitLocation = 0;

	for (i = 0, j = lengthOfString; i < lengthOfString, j >= 0; i++, j--)
	{
		bit = *(binaryNum + i) - '0'; // take away '0' (48 in ASCII)
									  // to get represented int
		bitValue = bit * power(2, j);
		
		decimalNum += bitValue;
	}

	bitLocation = decimalNum * 8;

	return bitLocation;
} // end getLocation

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
	int length = strlen(num1);
	long long binary1 = toBin(strtoll(num1, NULL, 2));
	long long binary2 = toBin(strtoll(num2, NULL, 2));
	char originalNum1[17];
	
	strncpy(originalNum1, num1, 16);
	originalNum1[16] = '\0';

	int i = 0;
	int remainder = 0;
	int sum[25];

	while (binary1 != 0 || binary2 != 0)
	{
		sum[i++] = (binary1 % 10 + binary2 % 10 + remainder) % 2;
		remainder = (binary1 % 10 + binary2 % 10 + remainder) / 2;
		binary1 = binary1 / 10;
		binary2 = binary2 / 10;
	}

	if (remainder != 0)
	{
		sum[i++] = remainder;
	}

	--i;

	int position = (length - 1) - i;

	// Copy sum into result
	while (i >= 0)
	{
		result[(length - 1) - i] = sum[i] + '0';
		--i;
	}

	// Handle empty bits
	while (position >= 0)
	{
		--position;
		if (position >= 0)
		{
			result[position] = '0';
		}
	}

	// Check Negative flag
	if (result[0] == '1')
	{
		// Set negative flag
		statusRegister[0] = '1';
	}
	else
	{
		statusRegister[0] = '0';
	}
	
	// Check Zero flag
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
	else
	{
		statusRegister[1] = '0';
	}

	// Check Overflow
	int overflow = 0;

	if (originalNum1[0] == '1' && num2[0] == '1')
	{
		if (result[0] == '0')
		{
			overflow = 1;
		}
	}
	else if (originalNum1[0] == '0' && num2[0] == '0')
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
	else
	{
		statusRegister[2] = '0';
	}
	
	// Check Carry
	if (sum[strlen(result)] == 1)
	{
		// Set carry bit
		statusRegister[3] = '1';
	}
	else
	{
		statusRegister[3] = '0';
	}

	return 0;
} // end addBinaryNumbers
