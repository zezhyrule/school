// size of array is passed as integer
// default size for default constructor should be 20
// handle if it's full and you try to add new values
//
// keep track of size, empty elements, etc
//
// figure out a way to see how big file is before creating array
// read thru once to count num of lines then move fp to beginning again

#include <iostream>
#include <fstream>
#include <string>
#include "Dictionary.h"

Dictionary loadDictionaryFromFile(std::string filename);

int main(int argc, char** argv)
{
	// Obtain filename from command line argument
	std::string filename;
	if (argc > 1)
	{
		filename = argv[1];
	}

	// Create dictionary object from given file
	Dictionary myBooks = loadDictionaryFromFile(filename);

	// Main loop
	std::string input;
	bool loop = true;
	do
	{
		std::cout << "\nEnter ISBN to search for book title. (? for more options)\n ";
		std::cout << "> ";
		std::cin >> input;
		std::cout << std::endl;

		if (input == "add" || input == "a")
		{
			keypair entry;

			std::cout << "What is the ISBN of book to add?" << std::endl;
			std::cout << "> ";
			std::cin >> entry.index;
			std::cout << "What is the title of the book?" << std::endl;
			std::cout << "> ";
			getline(std::cin, entry.value);
			getline(std::cin, entry.value);

			try
			{
				// add to dictionary object
				myBooks.addPair(entry);
				std::cout << "Book added to collection.\n";
			}
			catch (const char* e)
			{
				std::cout << std::endl << e << std::endl;
			}
		}
		else if (input == "print" || input == "p")
		{
			myBooks.printContents();
		}
		else if (input == "delete" || input == "d")
		{
			std::cout << "What is the ISBN of book to remove?\n";
			std::cout << "> ";
			std::cin >> input;
			
			myBooks.removePairOnIndex(input);

			std::cout << "If given book was in collection, it is no longer.\n";
		}
		else if (input == "exit" || input == "e" || input == "Exit")
		{
			loop = false;
			std::cout << "Exiting...\n";
		}
		else if (input == "?")
		{
			std::cout << "   Type [a]dd to create new entry, [p]rint to display contents\n";
			std::cout << "   [d]elete to remove entry, and [e]xit to quit.\n";
		}
		else
		{
			try
			{
				std::cout << "Book found: " <<myBooks.searchIndex(input) << std::endl;
			}
			catch (const char* e)
			{
				std::cout << e << std::endl;
			}
		}

	} while (loop);

	return 0;

} // end main

Dictionary loadDictionaryFromFile(std::string filename)
{
	// Obtain filename to dictionary datafile
	std::string filepath = "/home/courses/cs3311/ProgramFiles/";
	filepath.append(filename);

	// Determine number of entries in the book
	int numOfEntries = 0;

	std::ifstream dataFile(filepath);
	std::string temp;
	
	while (getline(dataFile, temp))
	{
		numOfEntries++;
	}

	// Return file pointer to beginning of file
	dataFile.clear();
	dataFile.seekg(0, std::ios::beg);

	// Create dictionary of size determined
	Dictionary myBooks(numOfEntries);

	// Get book data from file and enter into dictionary
	std::string fileline;
	std::string delimiter = " ";
	keypair entry;

	for (int i = 0; i < numOfEntries; i++)
	{
		// Get a line from the file
		getline(dataFile, fileline);

		// Grab the ISBN (every character on the line up to the first space)
		entry.index = fileline.substr(0, fileline.find(delimiter));

		// Remove the ISBN and space from the fileline string
		fileline.erase(0, fileline.find(delimiter) + delimiter.length());

		// The remaining characters in the string make up the book title (value)
		entry.value = fileline;

		try
		{
			// add to dictionary object
			myBooks.addPair(entry);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
	}

	dataFile.close();

	return myBooks;

} // end loadDictionaryFromFile
