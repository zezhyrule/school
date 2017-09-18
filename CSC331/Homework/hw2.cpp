//---------------------------------------------------
// PROGRAM NAME: Homework 2
// PROGRAMMER:   Charlie Davis
// CLASS:        CSC 331.001, Fall 2017
// INSTRUCTOR:   Dr. C. Ivancic
//
// PROGRAM PURPOSE:
//
//
// SAMPLE INPUT:
//
//
// SAMPLE OUTPUT:
//
//
//---------------------------------------------------

#include<iostream>

using namespace std;

// main function
int main(int argc, char** argv)
{
	// Open file and read line by line
	return 0;
}
// end main

bool isPalindrome(char* str)
// -------------------------------------
// Takes in a c-style string and returns
// true if the string is a palindrome
// regardless of case.
// -------------------------------------
{
	bool palindrome = true;
	char* backwardString;

	strcpy(backwardString, reverseString(str));

	// Compare string and backwards string
	// character by character, ignoring case
	for (int i = 0; i < mystrlen(str); i++)
	{
		if (!compareChar(str[i], backwardString[i]))
		{
			palindrome = false;
		}
	} // end for

	return palindrome;
} // end isPalindrome

char* reverseString(char* str)
// ------------------------------------
// Reverses the sequence of characters
// in the passed string and returns the
// reversed string.
// ------------------------------------
{
	int stringLength = mystrlen(str);

	// Create a c-style string of the same
	// length as the passed string
	char backwardString[stringLength + 1];

	// Add null terminating character
	backwardString[stringLength] = '\0';

	// Decremnt stringLength so it represents the highest index
	stringLength--;

	// Loop through passed string and copy
	// in reverse into backwardString
	for (int i = 0; i < stringLength; i++)
	{
		backwardString[stringLength - i] = str[i];
	} // end for

	return backwardString;
} // end reverseString

bool compareChar(char ch1, char ch2)
{
// --------------------------------
// Compares two chars passed into
// function, ignoring case. Returns
// true if characters are the same.
// --------------------------------
	
	return tolower(ch1) == tolower(ch2);
} // end compareChar

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
