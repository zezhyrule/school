/*
PROGRAM NAME: Program 2, ADT Implementation and Use
PROGRAMMER:   Charles Davis
CLASS:        CSC 241.001, Fall 2016
INSTRUCTOR:   Dr. D. Dunn
DATE STARTED: September 24, 2016
DUE DATE:     September 27, 2016
REFERENCES:   /instr/Sphere.java - used for class template

PROGRAM PURPOSE:

Stores three date objects which can be displayed
and manipulated by the user using console input.

VARIABLE DICTIONARY:
	date1, p2Date - The first date object
	date2, p2Date - the second date object
	date3, p2Date - the third date object
	dateArray[], p2Date - an array of the date objects
	command, String - a variable to hold the user input
	dateNumber, int - specifies which date object to use

ADTs:
	p2Date

FILES USED:
	p2Date.java - the java implementation of the Date ADT

SAMPLE INPUTS:

G 2				
S 1 11/08/1996 
I 2				
D 1
D 2

SAMPLE OUTPUTS:

date 2 is 01/01/2000
date 1 was 01/01/2000 and is now 11/08/1996
date 2 is now 01/02/2000
date 1 is 11/08/1996  date 2 is 01/02/2000  date 3 is 05/30/2016
date 1 is Friday, November 8, 1996; date 2 is Sunday, January 2, 2000;
date 3 is Monday, May 30, 2016;
---------------------------------------------------------------------
*/

import java.util.*;

public class p2 extends p2Date
{
	public static void main(String[] args)
	{
		p2Date date1 = new p2Date();
		p2Date date2 = new p2Date();
		p2Date date3 = new p2Date(5, 31, 2016);
		p2Date[] dateArray = new p2Date[4]; // create an array to make
		dateArray[0] = null;                // choosing the object more
		dateArray[1] = date1;				// simple 
		dateArray[2] = date2;
		dateArray[3] = date3;
		Scanner input = new Scanner(System.in);
		String command;
		int dateNumber = 0;

		do // main loop
		{
			System.out.print("\nEnter a command: ");
			command = input.nextLine();

			if (command.length() > 1) // make sure no exception is thrown
				dateNumber = Character.getNumericValue(command.charAt(2));


			if (command.charAt(0) == 'G') // Get date
			{
				System.out.print("date " + dateNumber + " is ");
				dateArray[dateNumber].displayDateRegular();
			}
			else if (command.charAt(0) == 'S') // Set date
			{
				String changedDate = command.substring(4);
				
				System.out.print("date " + dateNumber + " was ");
			    dateArray[dateNumber].displayDateRegular();
				dateArray[dateNumber].setDate(changedDate);
				System.out.print(" and is now ");
			   	dateArray[dateNumber].displayDateRegular();
			}
			else if (command.charAt(0) == 'I') // Increment date
			{
				dateArray[dateNumber].incrementDay();
				System.out.print("date " + dateNumber + " is now ");
				dateArray[dateNumber].displayDateRegular();
			}
			else if (command.charAt(0) == 'D') // Display date
			{
				if (dateNumber == 1)
				{
					for (int i = 1; i < 4; i++)
					{
						System.out.print("date " + i + " is ");
						dateArray[i].displayDateRegular();
						System.out.print("  ");
					}
				}
				else if (dateNumber == 2)
				{
					for (int i = 1; i < 4; i++)
					{
						System.out.print("date " + i + " is ");
						dateArray[i].displayDateWords();
						System.out.print("; ");
					}
				}
			}
			else if (command.charAt(0) != 'Q')
			{
				System.out.println("Command not recognized. Type Q to quit.");
			}
			else
				break;
		}while (command != "Q"); // end main loop

		System.out.println("Thank you for using my program!");
	} // end main
}
