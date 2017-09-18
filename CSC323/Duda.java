//---------------------------------------------------
// PROGRAM NAME:	    Duda
// ORIGINAL PROGRAMMER: 
// PROGRAM MODIFIED BY:	Charlie Davis
// CLASS:		        CSC 323.001, Fall 2017
// INSTRUCTOR:		    Dr. D. Cook
//
// PROGRAM PURPOSE:
//
// Reads numbers in from file, sums them, and prints sum.
//
// SAMPLE INPUT:
//
// 4
// 2   8
// 3 
//
// 2
//
// SAMPLE OUTPUT:
//
// Move on, it's done. Oh you need it... no it's mine now.
// The total is: 15
//
//---------------------------------------------------

import java.util.*;
import java.io.*;

public class Duda
{
	public static void main(String[] args)
	{
		int[] wil1 = getNumbersFromFile();

		if (wil1 != null)
		{
			int will=wil1[0];  
			int wi1l=wil1[1];
			int wiIl=wil1[2];
			int wiII=will-wiIl+wi1l+wiIl+wiIl;

			for (int i = 3; i < wil1.length; i++)
			{
				wiII += wil1[i];
			}
			System.out.println("Move on, it's done. Oh you need it... no it's mine now.");
			System.out.println("The total is: " + wiII);
		} // end if
	} // end main

	public static int[] getNumbersFromFile()
	{
	// -------------------------------------------
	// Opens a user-specified file, grabs numbers
	// from the file and puts them into an array
	// which is returned.
	// Precondition: File exists, first number in
	// file is number of data elements in file.
	// Postcondition: An array containing the
	// numbers from the file is returned.
	// -------------------------------------------
		
		try
		{	
			Scanner input = new Scanner(System.in);

			// Get filename from user
			System.out.print("\nEnter name of a file containing numbers: ");
			String filename = input.next();
			System.out.println();

			// Attempt to open file
			File file = new File(filename);
			Scanner fileStream = new Scanner(file);

			// Determine number of data elements
			int[] numberArray = new int[fileStream.nextInt()]; // Array to hold numbers

			// Read in numbers from file
			for (int i = 0; i < numberArray.length; i++)
			{
				if (fileStream.hasNextInt())
				{
					numberArray[i] = fileStream.nextInt();
				}
			} // end for

			// Close file if open
			if (fileStream != null)
			{
				fileStream.close();
			}

			return numberArray;
		} // end try
		catch (FileNotFoundException e)
		{
			System.out.println(e);
		} // end catch

		return null;
	} // end getNumbersFromFile


}

































//used int on purpose, willwil1wi1lwi11 all written the differently but none look the same. Good luck.
