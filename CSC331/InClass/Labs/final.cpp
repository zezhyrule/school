// -------------------------------------------
//
// Program: final.cpp
// Purpose: Tests the GlassQueue class.
//			reads data from file and
//			prints colors in turn.
//
//	Author: Charles Davis
//
//	-----------------------------------------

#include <iostream>
#include<fstream>
#include <string>

#include "GlassQueue.hpp"

int main(int argc, const char** argv)
{
	// Create queues for each glass color
	GlassQueue<std::string>* redQueue = new GlassQueue<std::string>();
	GlassQueue<std::string>* orangeQueue = new GlassQueue<std::string>();
	GlassQueue<std::string>* yellowQueue = new GlassQueue<std::string>();
	GlassQueue<std::string>* greenQueue = new GlassQueue<std::string>();
	GlassQueue<std::string>* blueQueue = new GlassQueue<std::string>();
	GlassQueue<std::string>* violetQueue = new GlassQueue<std::string>();

	// ------------------
	//      FILE IO
	// ------------------
	
	// Input stream for operating on files
	std::ifstream file;

	// Data file contains strings to populate queues
	file.open("final_exam.dat");

	// Read file line by line
	if (file.is_open())
	{
		int counter = 0; // Counts number of data items in file
		std::string color;

		// Loop through data file and populate appropriate queues
		while (getline(file, color))
		{
			if (color == "RED")
			{
				redQueue->enqueue(color);
				counter++;
			}
			else if (color == "ORANGE")
			{
				orangeQueue->enqueue(color);
				counter++;
			}
			else if (color == "YELLOW")
			{
				yellowQueue->enqueue(color);
				counter++;
			}
			else if (color == "GREEN")
			{
				greenQueue->enqueue(color);
				counter++;
			}
			else if (color == "BLUE")
			{
				blueQueue->enqueue(color);
				counter++;
			}
			else if (color == "VIOLET")
			{
				violetQueue->enqueue(color);
				counter++;
			}
		}

		// Loop through queues, dequeueing and printing in turn
		while (counter != 0)
		{

			// Print RED value
			if (!redQueue->isEmpty())
			{
				std::cout << redQueue->dequeue() << std::endl;;
				counter--;
			}

			// Print ORANGE value
			if (!orangeQueue->isEmpty())
			{
				std::cout << orangeQueue->dequeue() << std::endl;;
				counter--;
			}

			// Print YELLOW value
			if (!yellowQueue->isEmpty())
			{
				std::cout << yellowQueue->dequeue() << std::endl;;
				counter--;
			}

			// Print GREEN value
			if (!greenQueue->isEmpty())
			{
				std::cout << greenQueue->dequeue() << std::endl;;
				counter--;
			}

			// Print BLUE value
			if (!blueQueue->isEmpty())
			{
				std::cout << blueQueue->dequeue() << std::endl;;
				counter--;
			}

			// Print VIOLET value
			if (!violetQueue->isEmpty())
			{
				std::cout << violetQueue->dequeue() << std::endl;;
				counter--;
			}
		}

	}
	else
	{
		std::cout << "\nError: File not found.\n" << std::endl;
	}

	file.close();

	return 0;
}
