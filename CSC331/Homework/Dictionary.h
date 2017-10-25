#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>

//Treat this as one object that stores both pieces of information.
struct keypair
{
	std::string index;
	std::string value;
};

//Dictionary class.
class Dictionary
{
	public:
		//Three constructors used to set the values of the object;
		Dictionary();
		Dictionary(int);
		Dictionary(keypair, int);

		//Destructor to free up space
		~Dictionary();

		//Add a new keypair element to the array.
		void addPair(keypair);

		//Remove a keypair based on some index value
		void removePairOnIndex(std::string);

		//Search the array for the value associated with an index.
		std::string searchIndex(std::string);

		//Print out the contents of the object.
		void printContents();

	private:
		//Book is our dictionary array.
		keypair* book;

		//Size is the number of keypair elements in the array
		//Capacity is the max size of the array.
		int size, capacity;
};

#endif
