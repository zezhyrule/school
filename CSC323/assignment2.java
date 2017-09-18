// ---------------------------------------------------------------------
// PROGRAM NAME: Assignment 2
// PROGRAMMER:   Charlie Davis
// CLASS:        CSC 323.001, Fall 2017
// INSTRUCTOR:   Dr. D. Cook
// DUE DATE:     September 11, 2017
// PROGRAM PURPOSE: Gets 3 numbers from a file and 1 from a user and averages them.
//
// SAMPLE INPUTS:
// 
// 1 2    9
// 5
//
// SAMPLE OUTPUTS:
//   
// The average of 1.0, 2.0, 9.0, and 5 is: 4.25
// ---------------------------------------------------------------------

import java.io.*;
import java.util.*;

public class assignment2
{	
	public static void main(String[] args)
	{
		// Grab three numbers from file and put into array
		double[] numberArray = getNumbersFromFile();

		if (numberArray != null)
		{
			// Obtain number from user
			Scanner input = new Scanner(System.in);
			System.out.print("Now enter a fourth number: ");
			numberArray[3] = input.nextDouble();

			// Average numbers and print to screen
			double sum = 0;
			for (int i = 0; i < numberArray.length; i++)
			{
				sum += numberArray[i];
			}
			double average = sum / 4;

			System.out.println("The average of " + numberArray[0] + ", " +
					numberArray[1] + ", " + numberArray[2] + ", and " + numberArray[3] +
					" is: " + average);
		} // end if
	} // end main

	public static double[] getNumbersFromFile()
	{
	// -------------------------------------------
	// Opens a user-specified file, grabs three
	// numbers from the file and puts them into
	// a double array which is returned.
	// -------------------------------------------
	
		Scanner input = new Scanner(System.in);
		double[] numbers = new double[4]; // Array to hold numbers
		boolean retry = false; // Loop variable

		do // Loop to allow user to respecify filename
		{
			try // Try block to catch if file is not found
			{
				// Get filename from user
				System.out.print("\nEnter name of file containing three numbers: ");
				String filename = input.next();
				System.out.println();

				// Attempt to open file
				File file = new File(filename);
				Scanner fileStream = new Scanner(file);

				// Read in numbers from file
				for (int i = 0; i < 3; i++)
				{
					if (fileStream.hasNextDouble())
					{
						numbers[i] = fileStream.nextDouble();
					}
					else // If three numbers don't exist, throw exception
					{
						throw new FileNotFoundException();
					}
				} // end for

				// Close file if open
				if (fileStream != null)
				{
					fileStream.close();
				}

				retry = false; // Do not loop again
			} // end try
			catch (FileNotFoundException e)
			{
				System.out.println("Error: Invalid file.");
				System.out.println("Do you want to try a different filename?");
				System.out.print("(y/n): ");
				String answer = input.next();

				// Determine if user wants to try again
				if (answer.equalsIgnoreCase("y") 
					|| answer.equalsIgnoreCase("yes"))
				{
					retry = true;
				}
				else
				{
					System.out.println("Program exited.\n");
					return null;
				}
			} // end catch
		} while (retry); // end do while

		return numbers;
	} // end getNumbersFromFile

} // end assignment2
