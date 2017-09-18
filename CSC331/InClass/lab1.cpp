#include<iostream>
#include<assert.h>
#include<string.h>

using namespace std;

int mystrlen(char* userString); // returns length of string

int main(int argc, char** argv)
{
	char userInput[100]; // Variable to hold user-entered string

	// Get input from console
	cout << "\nEnter a string: ";
	cin.getline(userInput, 100);

	// Display string and its length to screen
	cout << "The length of \"" << userInput << "\" is ";
	cout << mystrlen(userInput) << endl;

	// Verify the length with library function and print result
	assert(mystrlen(userInput) == strlen(userInput));
	cout << "Verification result: Pass\n\n";
	
	return 0;
} // end main

int mystrlen(char* userString)
{
// ----------------------------------------
// Determines size of C-style string passed
// into function and returns the length as
// an integer.
// ----------------------------------------
	int length = 0;
	int index = 0;

	while (userString[index] != '\0')
	{
		length++;
		index++;
	}

	return length;
} // end mystrlen
