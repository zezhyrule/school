/*
PROGRAM NAME: Program 4, Recursion and Stacks
PROGRAMMER:   Charles Davis
CLASS:        CSC 241.001, Fall 2016
INSTRUCTOR:   Dr. D. Dunn
DATE STARTED: October 23, 2016
DUE DATE:     October 25, 2016
REFERENCES:   Data Abstraction & Problem Solving with Java Textbook

PROGRAM PURPOSE:

Reads a list of student information from a data file. Puts data
into linked list and displays the student info to the screen.

VARIABLE DICTIONARY:
	StackA, p4StackA - Array-based implementation of stack
	StackP, p4StackP - Referenced-based stack
	licensePlate, String - six-character license number for ID of car
	action, char - action code that determines operation
	MAX_CARS, int - the max number of cars that fit in garage

ADTs:
	Stack

FILES USED:
	p4StackInterface.java - Interface for Stack ADT.
	p4StackA.java - array-based implementation of the Stack ADT.
	p4StackP.java - reference-based implementation of the Stack ADT.
	p4.sh - the script used to compile and run the program.

SAMPLE INPUTS:

dAAA111
aAAA111
aBBB222
aCCC333
aDDD444
aEEE555
aFFF666
v
aGGG777
aHHH888
xAAA999
aKKK999
aLLL000
aMMM111
dCCC333
aLLL111
dCCC333
aMMM222
dM99988
c


SAMPLE OUTPUTS:

Car AAA111 was not found in garage.
Car AAA111 was successfully parked.
Car BBB222 was successfully parked.
Car CCC333 was successfully parked.
Car DDD444 was successfully parked.
Car EEE555 was successfully parked.
Car FFF666 was successfully parked.

Cars in garage:
  FFF666
  EEE555
  DDD444
  CCC333
  BBB222
  AAA111

Car GGG777 was successfully parked.
Car HHH888 was successfully parked.
Error: Invalid Action Code.
Car KKK999 was successfully parked.
Car LLL000 was successfully parked.
Garage is full: Car MMM111 could not be parked.
Car CCC333 has departed.
Car LLL111 was successfully parked.
Car CCC333 was not found in garage.
Garage is full: Car MMM222 could not be parked.
Error: Invalid License Number.

---------------------------------------------------------------------
*/
import java.io.*;
import java.util.*;

public class p4
{
	public static void main(String[] args)
	{
		System.out.println("\nUSING ARRAY-BASED STACK:\n");
		p4StackA StackA = new p4StackA();
		processDataUsing(StackA);

		System.out.println("\nUSING REFERENCE-BASED STACK:\n");
		p4StackP StackP = new p4StackP();
		processDataUsing(StackP);
	} // end main

	public static void processDataUsing(p4StackInterface stack)
	{
	// -----------------------------------------------
	// Reads in data file containing action codes and
	// license plate numbers; Calls appropriate 
	// subroutine based on the action code.
	// Precondition: Data file exists at ../instr/p4.dat
	// Postcondition: License plate numbers from data
	// file are processed based on the action codes.
	// -----------------------------------------------
		try // try block to catch if file isn't found
		{
			File file = new File("../instr/p4.dat");
			Scanner fileStream = new Scanner(file);

			String fileline;
			String licensePlate;
			char action;

			// main loop
			while (fileStream.hasNextLine())
			{
				fileline = fileStream.next();
				action = fileline.charAt(0);

				//ARRIVAL
				if (action == 'a')
				{
					licensePlate = fileline.substring(1);
					if (isValidLicense(licensePlate))
					{
						arrival(stack, licensePlate);
					}
					else
					{
						System.out.println("Error: " +
								"Invalid License Number.");
					} // end if
				}
				//DEPARTURE
				else if (action == 'd') // ACTION CODE 'd'
				{
					licensePlate = fileline.substring(1);
					if (isValidLicense(licensePlate))
					{
						departure(stack, licensePlate);
					}
					else
					{
						System.out.println("Error: " +
								"Invalid License Number.");
					} // end if
				}
				//VIEW
				else if (action == 'v') // ACTION CODE 'v'
				{
					System.out.println("\nCars in garage:");
					view(stack);
					System.out.println();
				}
				//CLOSE
				else if (action == 'c') // ACTION CODE 'c'
				{
					break; // end while loop
				}
				else
				{
					System.out.println("Error: Invalid Action Code.");
				} // end if
			} // end while

			fileStream.close();
		} // end try
		catch (FileNotFoundException e)
		{
			System.out.println(e);
		} // end catch
	} // end processDataUsing 

	public static void arrival(p4StackInterface stack, String licensePlate)
	{
	// -----------------------------------------------
	// Adds car to "garage" stack, provided garage is
	// not full. Displays the license number and
	// whether it was successfully parked or not.
	// Precondition: stack is a Stack to which you
	// want to add a car. licensePlate identifies the car.
	// Postcondition: Car is added to nonfull stack.
	// Message is displayed specifying the license
	// number of the car and whether it was parked.
	// -----------------------------------------------
			final int MAX_CARS = 10;

			if (stack.getNumOfItems() < MAX_CARS)
			{
				stack.push(licensePlate);
				System.out.println("Car " + licensePlate +
						" was successfully parked.");
			}
			else
			{
				System.out.println("Garage is full: Car " + licensePlate +
						" could not be parked.");
			} // end if
	} // end arrival

	public static void departure(p4StackInterface stack, String licensePlate)
	{
	// -----------------------------------------------
	// Searches for car in garage by licensePlate and
	// removes it if found. Stack is otherwise unchanged.
	// Precondition: None.
	// Postcondition: Car matching licensePlate is 
	// removed from stack. Message printed to screen.
	// -----------------------------------------------
		Object item;
		
		if (stack.isEmpty())
		{
			System.out.println("Car " + licensePlate + " was not found in garage.");
			return; // match not found
		}

		item = stack.pop();

		if (licensePlate.equals(item)) 
		{
			System.out.println("Car " + licensePlate + " has departed.");
			return;
		}

		departure(stack, licensePlate);
		stack.push(item);
	} // end departure

	public static void view(p4StackInterface stack)
	{
	// -----------------------------------------------
	// Lists all the cars currently in the garage.
	// Precondition: stack is a Stack to be traversed.
	// Postcondition: The cars in the garage are
	// printed to the screen. stack is unchanged.
	// -----------------------------------------------
		Object item;

		if (stack.isEmpty())
		{
			return; // stack is empty; move back up the recursion
		} // end if

		item = stack.pop();
		System.out.println("  " + item);
		view(stack);
		stack.push(item);
	} // end view

	public static boolean isValidLicense(String licensePlate)
	{
	// -----------------------------------------------
	// Determines whether license is valid.
	// Precondition: licensePlate is a String.
	// Postcondition: Returns true if valid license;
	// otherwise returns false.
	// -----------------------------------------------
		boolean valid = true;

		// license plate must be of length six
		if (licensePlate.length() != 6)
		{
			valid = false;
		} // end if

		// first three characters must be capital letters
		for (int i = 0; i < 3; i++)
		{
			if (!Character.isLetter(licensePlate.charAt(i)) ||
				!Character.isUpperCase(licensePlate.charAt(i)))
			{
				valid = false;
			} // end if
		} // end for

		// next three characters must be numbers
		for (int i = 3; i < 6; i++)
		{
			if (!Character.isDigit(licensePlate.charAt(i)))
			{
				valid = false;
			} // end if
		} // end for

		return valid;
	} // end isValidLicense
} // end p4
