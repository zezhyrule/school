/*
PROGRAM NAME: Program 3, List Class
PROGRAMMER:   Charles Davis
CLASS:        CSC 241.001, Fall 2016
INSTRUCTOR:   Dr. D. Dunn
DATE STARTED: October 07, 2016
DUE DATE:     October 11, 2016
REFERENCES:   /instr/Sphere.java - used for class template
			  Dr. Dunn's Algorithm Handout - used for sorted list

PROGRAM PURPOSE:

Reads a list of student information from a data file. Puts data
into linked list and displays the student info to the screen.

VARIABLE DICTIONARY:
	list, p3List - The linked list of studentNodes
	fileLine, String - One line of a file
	studentData, String[] - An array of student's data
	name, String - the student's name
	studentID, String - the student's course ID
	courseID, String - the ID of a course taken by student
	credits, int - the credit hours for a course
	grade, char - the grade a student made in a course


ADTs:
	List

FILES USED:
	p3List.java - the java implementation of the List ADT.
	p3.sh - the script used to compile and run the program.

SAMPLE INPUTS:

Shiflet, Angela               1 CSC210 4 A
Blow, Joe                     5678 CSC121 3 B
Shiflet, Aaron                444 MTH101 3 B
Shiflet, Angela               1 CSC202 4 B
Blow, Joe                     5678 MTH099 3 C
King, Robert                  3808 MTH111 4 A
Blow, Joe                     5678 MTH110 4 B

SAMPLE OUTPUTS:

Blow, Joe           5678
       CSC121       3    B
       MTH099       3    C
       MTH110       4    B
         Total Credits: 10   Quality Points: 27   GPA: 2.700

King, Robert        3808
       MTH111       4    A
          Total Credits: 4   Quality Points: 16   GPA: 4.000

Shiflet, Aaron      444
       MTH101       3    B
          Total Credits: 3   Quality Points: 9    GPA: 3.000

Shiflet, Angela     1
       CSC210       4    A
       CSC202       4    B
          Total Credits: 8   Quality Points: 28   GPA: 3.500

---------------------------------------------------------------------
*/
import java.io.*;
import java.util.*;

public class p3 extends p3List
{
	public static void main(String[] args)
	{
		p3List list = new p3List();

		try // try block to catch if file isn't found
		{
			File file = new File("../instr/p3.dat");
			Scanner fileStream = new Scanner(file);

			String fileLine;
			String[] studentData;
			String name;
			String studentID;
			String courseID;
			int credits;
			char grade;

			while (fileStream.hasNextLine())
			{
				// gather all the data from one line and put into variables
				fileLine = fileStream.nextLine();
				name = fileLine.substring(0, 30).trim(); // name is in first 30 chars
				studentData = fileLine.substring(30).split("\\s");
				studentID = studentData[0];
				courseID = studentData[1];
				credits = Integer.parseInt(studentData[2]);
				grade = studentData[3].charAt(0);

				list.processStudent(name, studentID, courseID, credits, grade);
			} // end while

			fileStream.close();
		} // end try
		catch (FileNotFoundException e)
		{
			System.out.println(e);
		} // end catch

		list.displayList();
	} // end main
} // end p3
