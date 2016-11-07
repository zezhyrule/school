/*
PROGRAM NAME: Program 5, Queues/Inheritance
PROGRAMMER:   Charles Davis
CLASS:        CSC 241.001, Fall 2016
INSTRUCTOR:   Dr. D. Dunn
DATE STARTED: November 02, 2016
DUE DATE:     November 08, 2016
REFERENCES:   Data Abstraction & Problem Solving with Java Textbook

PROGRAM PURPOSE:

Reads in data from file and inserts into priority queue.

VARIABLE DICTIONARY:
	queue, p5PriorityQueue - referenced-based queue object
	command, char - the command to initiate
	letter, char - a lowercase letter code
	pVal, int - the priority value of the entry
	quit, boolean - if true, exit the loop and quit program

ADTs:
	Queue

FILES USED:
	p5Queue.java - referenced-based implementation of Queue ADT.
	p5PriorityQueue.java - child class of p5Queue; priority queue.
	p5.sh - the script used to compile and run the program.

SAMPLE INPUTS:

Ic10
Ia4
Ii7
P
Xh3
R
Id5
It-1
R
P
I32
R
Ix15
P
Q

SAMPLE OUTPUTS:

c inserted
a inserted
i inserted
a/4 => i/7 => c/10
Command X not found
a removed
d inserted
Invalid input
d removed
i/7 => c/10
Invalid input
i removed
x inserted
c/10 => x/15
Queue released. Quitting program.
---------------------------------------------------------------------
*/
import java.util.*;
import java.io.*;

public class p5
{
	public static void main(String[] args) throws Exception
	{
		p5PriorityQueue queue = new p5PriorityQueue();

		try // try block to catch if file isn't found
		{
			File file = new File("p5.dat");
			Scanner fileStream = new Scanner(file);

			String fileline;
			char command;
			char letter;
			int pVal;
			boolean quit = false;

			while (fileStream.hasNext() && quit == false)
			{
				fileline = fileStream.next();
				command = fileline.charAt(0);

				if (command == 'I') // insert into queue
				{
					letter = fileline.charAt(1);
					pVal = Integer.parseInt(fileline.substring(2));

					if (Character.isLowerCase(letter) && pVal >= 0)
					{
						queue.enqueue(letter, pVal);
						System.out.println(letter + " inserted");
					}
					else // invalid input
					{
						System.out.println("Invalid input");
					} // end if
				}
				else if (command == 'R') // remove first entry
				{
					if (!queue.isEmpty())
					{
						System.out.println(queue.dequeue() + " removed");
					} 
				}
				else if (command == 'P') // print queue
				{
					queue.printQueue();
					System.out.println();
				}
				else if (command == 'Q') // clear queue and quit
				{
					System.out.println("Queue released. Quitting program.");
					queue.dequeueAll();
					quit = true;
				}
				else // invalid command
				{
					System.out.println("Command " + command + " not found");
				} // end if
			} // end while

			fileStream.close();
		} // end try
		catch (FileNotFoundException e)
		{
			System.out.println(e);
		} // end catch
	} // end main

} // end p5
