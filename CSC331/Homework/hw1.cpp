//---------------------------------------------------
// PROGRAM NAME: Homework 1
// PROGRAMMER:   Charlie Davis
// CLASS:        CSC 331.001, Fall 2017
// INSTRUCTOR:   Dr. C. Ivancic
//
// PROGRAM PURPOSE:
//
// Asks user to enter a single character and prints
// the character to the console.
//
// SAMPLE INPUT:
//
// K
//
// SAMPLE OUTPUT:
//
// You entered: K
//
//---------------------------------------------------

#include<iostream>

using namespace std;

// main function
int main(int argc, char** argv)
{
	char userInput; // Variable to hold user-entered character

	// Get input from console
	cout << "Enter a single character: ";
	cin >> userInput;

	// Display character to screen
	cout << "\nYou entered: " << userInput << endl;

	return 0;
}
// end main
