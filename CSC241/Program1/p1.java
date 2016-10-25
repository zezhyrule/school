/*
PROGRAM NAME: Program 1, Software Engineering and Modular Design
PROGRAMMER:   Charles Davis
CLASS:        CSC 241.001, Fall 2016
INSTRUCTOR:   Dr. D. Dunn
DATE STARTED: September 1, 2016
DUE DATE:     September 13, 2016
REFERENCES:   

PROGRAM PURPOSE:
a. This program reads student names and scores from a source file
b. The program prints each name and averaged score for each student
   along with a course grade and class average

VARIABLE DICTIONARY:
	NUMBER_OF_POINT_VALUES, int
	NUMBER_OF_ENTRIES, int
	fileData, String[][] - the data from the file in a 2D array
	pointValues, int[] - the max points possible for each score
	students, Student[]
	name, String
	scores, int[] - individual students' scores
	averagedScores, double[]
	overallAverage, double
	courseGrade, char

   
ADTs:
   none

FILES USED:
   p1.dat - a file containing names and scores

SAMPLE INPUTS:
	100 100 100 200 50 50 25 50 50 15 35 22 15 10 20 15 20 30 20 15
	Jack Johnson 85 83 79 182 50 45 20 50 45 15 32 18 13 9 18 15 15 20 18 13
	Lisa Adams 80 90 95 101 40 40 20 50 48 13 32 20 9 5 18 15 18 25 18 13

SAMPLE OUTPUTS:
	Name         Test 1 Test 2 Test 3 Test 4 Lab 1  Lab 2  Lab 3  Lab 4  Lab 5  HW 1   HW 2   HW 3   HW 4   HW 5   HW 6   Quiz 1 Quiz 2 Quiz 3 Quiz 4 Quiz 5
	Jack Johnson 85.00  83.00  79.00  91.00 100.00  90.00  80.00 100.00  90.00 100.00  91.43  81.82  86.67  90.00  90.00 100.00  75.00  66.67  90.00  86.67
	Average: 87.00
	Grade: B


	Lisa Adams   80.00  90.00  95.00  50.50  80.00  80.00  80.00 100.00  96.00  86.67  91.43  90.91  60.00  50.00  90.00 100.00  90.00  83.33  90.00  86.67
	Average: 83.00
	Grade: B


	Overall Grade: 71.00
---------------------------------------------------------------------
*/

import java.util.*;
import java.io.*;

public class p1 extends Student
{
	final static int NUMBER_OF_POINT_VALUES = 20;
	final static int NUMBER_OF_ENTRIES = 4;

	public static void main (String[] args)
	{
		String[][] fileData = new String[NUMBER_OF_ENTRIES + 1][NUMBER_OF_POINT_VALUES + 2];
		int[] pointValues = new int[NUMBER_OF_POINT_VALUES];
		Student[] students = new Student[NUMBER_OF_ENTRIES];

		fileData = getDataFromFile(fileData);
		pointValues = populatePointValuesArray(fileData, pointValues);
		students = populateStudentArray(fileData, students);

		//move this after documentation if time
		for (int i = 0; i < NUMBER_OF_ENTRIES; i++)
		{
			students[i].setAveragedScores(calculateAveragedStudentScores(pointValues,
									      students[i]));
		}

		displayScores(students);

	} // end main

	public static String[][] getDataFromFile(String[][] fileData)
	{
	// -----------------------------------------------------------
	// Takes data and puts into 2D array.
	// Precondition: Requires a 2D array to be passed into the 
	// method with the same rows and columns as are in the data
	// file.
	// Postcondition: Returns a 2D array with the first row
	// being the max possible values for each assignment
	// and the following rows containing student values
	// ----------------------------------------------------------
		Scanner fileStream;
		File file = new File("../instr/p1.dat");

		try
		{
			fileStream = new Scanner(file);

			while (fileStream.hasNext())
			{

				for (int i = 0; i < fileData.length; i++)
				{
					for (int j = 0; j < fileData[i].length; j++)
					{
						if (i == 0 && j == 0)
						{
							j = j + 2; //because first line contains no name
						}

						fileData[i][j] = fileStream.next();
					}
				}
			} // end while

			fileStream.close();

		} // end try
		catch (FileNotFoundException e)
		{
			System.out.println(e);
		} // end catch

		return fileData;
	}

	public static int[] populatePointValuesArray(String[][] fileData, int[] pointValues)
	{
	// -----------------------------------------------------------
	// Fills pointsValues array with values.
	// Precondition: 2D array fileData is populated with values.
	// This method will take the first row of fileData and
	// convert them into a 1D int array, pointValues.
	// Postcondition: Returns a 1D int array containing the data
	// from the first row of fileData.
	// ----------------------------------------------------------
		for (int i = 0; i < NUMBER_OF_POINT_VALUES; i++)
		{
			pointValues[i] = Integer.parseInt(fileData[0][i+2]); 

			//the first two elements in the fileData array are null
			//because there is no student name on this line of data
		}

		return pointValues;
	}

	public static Student[] populateStudentArray(String[][] fileData, Student[] students)
	{
	// -----------------------------------------------------------
	// Creates student objects and stores in array.
	// Precondition: The 2D fileData array, starting on the 2nd
	// row, contains information for each student.
	// Postcondition: Returns an array of Student objects filled
	// with the values from the fileData array.
	// ----------------------------------------------------------
		Student[] studentArray = students;
		int[][] scoresArray = new int[studentArray.length][NUMBER_OF_POINT_VALUES];

		for (int i = 0; i < NUMBER_OF_ENTRIES; i++)
		{
			//adds the student's first and last name, the first two elements in each array
			//skips the first row of the fileData array because it's the max point values
			studentArray[i] = new Student(fileData[i+1][0] + " " + fileData[i+1][1]);

			for (int j = 0; j < NUMBER_OF_POINT_VALUES; j++)
			{
				// the scores for each student start on the third element of each array
				scoresArray[i][j] = Integer.parseInt(fileData[i+1][j+2]);
			}

			studentArray[i].setScores(scoresArray[i]);
		}


		return studentArray;
	}

	public static double[] calculateAveragedStudentScores(int[] pointValues, Student student)
	{
	// -----------------------------------------------------------
	// Calculates each student score to be displayed out of 100
	// Precondition: This method takes the max point values array
	// and a student object.
	// Postcondition: The student object now contains correctly
	// calculated scores out of 100 for each assignment.
	// ----------------------------------------------------------
		int[] scoresArray = student.getScores();
		double[] averagedScoresArray = new double[scoresArray.length];

		for (int i = 0; i < scoresArray.length; i++)
		{
			averagedScoresArray[i] = (double)scoresArray[i];
		}

		for (int i = 0; i < averagedScoresArray.length; i++)
		{
			// divide the scores by the max point value to get a value out of 100
			averagedScoresArray[i] = (averagedScoresArray[i] / pointValues[i]) * 100.0;
			// round to two decimal places
			averagedScoresArray[i] = Math.round(averagedScoresArray[i] * 100.0) / 100.0;
		}

		return averagedScoresArray;

	}

	public static void displayScores(Student[] students)
	{
	// -----------------------------------------------------------
	// Displays the formatted scores.
	// Precondition: An array of Student objects.
	// Postcondition: Scores are displayed for each student,
	// along with the calculated course average
	// ----------------------------------------------------------
		String name;
		double studentAverage;
		double classAverage = 0;

		System.out.println("Name         Test 1 Test 2 Test 3 Test 4 Lab 1  Lab 2  Lab 3  Lab 4  Lab 5  HW 1   HW 2   HW 3   HW 4   HW 5   HW 6   Quiz 1 Quiz 2 Quiz 3 Quiz 4 Quiz 5");

		for (int i = 0; i < NUMBER_OF_ENTRIES; i++)
		{
			name = students[i].getName();	
			studentAverage = students[i].getOverallAverage();
			classAverage += studentAverage;

			System.out.print(name);

			for (int x = name.length(); x < 12; x++)
			{
				System.out.print(" ");
			}

			for (int j = 0; j < NUMBER_OF_POINT_VALUES; j++)
			{
				System.out.printf("%6.2f", students[i].getAveragedScores()[j]);
				System.out.print(" ");
			}

			System.out.println();
			System.out.printf("Average: %.2f", studentAverage);
			System.out.println("\nGrade: " + students[i].getCourseGrade());
			System.out.println();
			System.out.println();

		}

		classAverage = Math.round((classAverage / NUMBER_OF_ENTRIES) * 100) / 100;

		System.out.printf("Class average = %.2f", classAverage);

	}
	
}

class Student
{
	private String name = "";
	private int[] scores;
	private double[] averagedScores;
	private double overallAverage;
	private char courseGrade;

	public Student()
	{
		this.name = "";
	}

	public Student(String name)
	{
		this.name = name;
	}

	public String getName()
	{
		return this.name;
	}

	public void setName(String name)
	{
		this.name = name;
	}

	public int[] getScores()
	{
		return this.scores;
	}

	public void setScores(int[] scores)
	{
		this.scores = scores;
	}

	public double[] getAveragedScores()
	{
		return this.averagedScores;
	}

	public void setAveragedScores(double[] averagedScores)
	{
		this.averagedScores = averagedScores;
	}

	// -----------------------------------------------------------
	// Calculates student's average.
	// Precondition: averagedScores must be populated.
	// Postcondition: Calculates overallAverage rounded to 2
	// decimal places.
	// ----------------------------------------------------------
	public double getOverallAverage()
	{
		double add = 0;

		for (int i = 0; i < this.averagedScores.length; i++)
		{
			add += averagedScores[i];
		}
		
		this.overallAverage = Math.round((add / (averagedScores.length)) * 100) / 100;

		return this.overallAverage;
	}

	// -----------------------------------------------------------
	// Gets the course grade.
	// Precondition: overallAverage is used.
	// Postcondition: Displays appropriate grades from A-F based
	// on student's overallAverage.
	// ----------------------------------------------------------
	public char getCourseGrade()
	{
		if (this.overallAverage >= 90)
		{
			this.courseGrade = 'A';
		}
		else if (this.overallAverage >= 80)
		{
			this.courseGrade = 'B';
		}
		else if (this.overallAverage >= 70)
		{
			this.courseGrade = 'C';
		}
		else if (this.overallAverage >= 60)
		{
			this.courseGrade = 'D';
		}
		else
		{
			this.courseGrade = 'F';
		}

		return this.courseGrade;
	}
}
