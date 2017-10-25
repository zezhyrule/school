#include "Dictionary.h"
#include <iostream>
#include <string>

Dictionary::Dictionary()
{
	// Default capacity
	this->capacity = 20;
	// Create dictionary array of this default size
	this->book = new keypair[this->capacity];
	// Initialize size
	this->size = 0;
}

Dictionary::Dictionary(int capacity)
{
	this->capacity = capacity;
	// Create dictionary array of size given
	this->book = new keypair[this->capacity];
	// Initialize size
	this->size = 0;
}

// Constructor setting initial keypair and capacity
Dictionary::Dictionary(keypair entry, int capacity)
{
	this->capacity = capacity;

	// Create dictionary array of size given
	this->book = new keypair[this->capacity];
	// Set initial entry and set size to 1
	this->book[0] = entry;
	this->size = 1;
}

// Destructor
Dictionary::~Dictionary()
{
	delete[] this->book;
}

// Add a new keypair element to the array
void Dictionary::addPair(keypair entry)
{
	// Check if the array is already full
	if (this->size >= this->capacity)
	{
		// Throw an exception if array has reached capacity
		throw "The dictionary is full. Remove an element to add more.";
	}
	else
	{
		// Boolean variable to see if empty spot was found
		bool found = false;

		// Loop through array to find empty location
		for (int i = 0; i < this->capacity, found != true; i++)
		{
			// Check if location is empty
			if (this->book[i].index.length() <= 0)
			{
				this->book[i] = entry;
				this->size++;
				found = true;
			}
		}
	}
} // end addPair

// Remove a keypair based on some index value
void Dictionary::removePairOnIndex(std::string searchIndex)
{
	for (int i = 0; i < this->capacity; i++)
	{
		// Check if search index matches index in book
		if (this->book[i].index == searchIndex)
		{
			// Remove entry and reduce size
			this->book[i].index = "";
			this->size--;
		}

	}
} // end removePairOnIndex

// Search the array for the value associated with an index
std::string Dictionary::searchIndex(std::string searchIndex)
{
	std::string foundValue = "";

	for (int i = 0; i < this->capacity; i++)
	{
		// Check if search index matches index in book
		if (this->book[i].index == searchIndex)
		{
			// Grab value if it exists
			foundValue = this->book[i].value;
		}
	}

	if (foundValue == "")
	{
		throw "Entry not found.";
	}

	return foundValue;
} // end searchIndex

// Print out the contents of the object.
void Dictionary::printContents()
{
	std::cout << "------------------------------------" << std::endl;
	std::cout << "        Dictionary Entries" << std::endl;
	
	for (int i = 0; i < this->capacity; i++)
	{
		if (this->book[i].index.length() > 0)
		{
			std::cout << "\n   ISBN: " << this->book[i].index;
			std::cout << "\n  Title: " << this->book[i].value;
			std::cout << "\n\n";
		}
	}

	std::cout << "------------------------------------" << std::endl;

} // end printContents
