//---------------------------------------------------
// PROGRAM NAME: Homework 2
// PROGRAMMER:   Charlie Davis
// CLASS:        CSC 331.001, Fall 2017
// INSTRUCTOR:   Dr. C. Ivancic
//
// PROGRAM PURPOSE: Reads in strings line-by-line from
// the file passed as a commandline argument and 
// and determines if each string is a palindrome.
//
// SAMPLE INPUT:
//
// Abcddcba
// Arewenotdrawnonwardtonewera
// Ispalindromeapalindrome
// AbcdBA
// alula
// AtoyotasaToyota
// Stephenfaustinstateuniversity
// J
//
// SAMPLE OUTPUT:
//
// "Abcddcba" is a palindrome.
// "Arewenotdrawnonwardtonewera" is a palindrome.
// "Ispalindromeapalindrome" is not a palindrome.
// "AbcdBA" is not a palindrome.
// "alula" is a palindrome.
// "AtoyotasaToyota" is a palindrome.
// "Stephenfaustinstateuniversity" is not a palindrome.
// "J" is a pali
//
//---------------------------------------------------

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

bool isPalindrome(string &str); // Determines if string is palindrome
void reverseString(string &str); // Reverses a given string
bool compareChar(char ch1, char ch2); // Compares chars, ignoring case

// main function
int main(int argc, char** argv)
{
	ifstream file; // Input stream for operating on files
	string fileline; // Variable to hold one line from file
	char* filename = argv[1]; // filename given by commandline arg

	if (argc > 1)
	{
		// Open file
		file.open(filename);
	}
	else
	{
		cout << "Please enter a filename after name of program.";
	}

	// Read line by line
	if (file.is_open())
	{
		cout << endl;
		while (getline(file, fileline))
		{
			// Print word and say whether it is a palindrome or not
			cout << "\"";
		    cout << fileline;
			cout	<< "\" is ";

			if (!isPalindrome(fileline))
			{
				cout << "not ";
			}

			cout << "a palindrome." << endl;
		} // end while
		cout << endl;
	}
	else
	{
		cout << "\nError: File not found.\n" << endl;
	}

	file.close();

	return 0;
} // end main

bool isPalindrome(string &str)
// -------------------------------------
// Takes in a string and returns
// true if the string is a palindrome
// regardless of case.
// -------------------------------------
{
	bool palindrome = true;
	string originalString = str;

	reverseString(str);

	// Compare string and backwards string
	// character by character, ignoring case
	for (int i = 0; i < str.length(); i++)
	{
		if (!compareChar(str.at(i), originalString.at(i)))
		{
			palindrome = false;
		}
	} // end for

	return palindrome;
} // end isPalindrome

void reverseString(string &str)
// ------------------------------------
// Reverses the sequence of characters
// in the passed string and returns the
// reversed string.
// ------------------------------------
{
	int stringLength = str.length();
	string backwardString = str;

	// Decrement stringLength so it represents the highest index
	stringLength--;

	// Loop through passed string and copy
	// in reverse into backwardString
	for (int i = 0; i < stringLength; i++)
	{
		swap(backwardString[stringLength - i],  str[i]);
	}
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

