#include<iostream>
#include"Mobile.h"

//Constructor
Mobile::Mobile(std::string model, std::string serialnumber, std::string phoneNumber)
{
	this->model = model;
	this->serialnumber = serialnumber;
	this->phoneNumber = phoneNumber;
	this->hasSim = false;
	this->contactSize = 0;
	this->simNum = "";
	this->contactList = new Contact[CONTACT_CAPACITY];
	std::cout << "New phone initialized.\n";
}
//Destructor
Mobile::~Mobile()
{
	delete[] contactList;
}
//This method takes a string and checks it to see if it is a valid number.  The number must only have
//digits in it and must be in format xxx-xxx-xxxx.  Returns 0 if valid number and -1 if incorrect.
int Mobile::checkNum(std::string num)
{
	if (num.length() < 12)
		return -1;

	bool valid = true;
	for (unsigned int i = 0; i < num.length(); i++)
	{
		switch (i)
		{
			//Check if the number in the digits spots are between 0 and 9
		case 0:
		case 1:
		case 2:
		case 4:
		case 5:
		case 6:
		case 8:
		case 9:
		case 10:
		case 11:
			if (num[i] < 48 || num[i] > 57)
				valid = false;
			break;
		//Check if the other characters are -
		case 3:
		case 7:
			if (num[i] != '-')
				valid = false;
			break;
		default:
			break;

		}
		if (valid == false)
			return -1;
	}
	return 0;
}
//Takes a Contact struct object and uses it to add the contact information to the list.
void Mobile::addContact(Contact c)
{
	//If the contact list is full, throw an exception;
	if (this->contactSize >= CONTACT_CAPACITY)
		throw "Cannot add another contact.  List is full.";
	else
	{
		//Check if number is valid format. if not throw exception.
		int valid = this->checkNum(c.number);
		if (valid == -1)
			throw "Number is in incorrect format.  Please enter it in XXX-XXX-XXXX format.";
		else
		{
			this->contactList[this->contactSize] = c;
			(this->contactSize)++;
		}
	}
}
//Overloaded.  Takes the strings, creates a struct object, and sends it to the other method
void Mobile::addContact(std::string num, std::string name)
{
	Contact temp;
	temp.name = name;
	temp.number = num;
	this->addContact(temp);
}
//Add a sim card with the sim id
void Mobile::addSim(std::string sim)
{
	this->simNum = sim;
	this->hasSim = true;
}
//Removes the sim id
void Mobile::removeSim()
{
	this->simNum = "";
	this->hasSim = false;
}
std::string Mobile::getSimInfo()
{
	return this->simNum;
}
//Print the entire contacts list
void Mobile::printContacts()
{
	for (int i = 0; i < this->contactSize; i++)
	{
		std::cout << "Contact " << i << ": " << this->contactList[i].name << ", " << this->contactList[i].number << std::endl;
	}
}
//Method takes a nubmer and calls the number.  The string is thenumber to call.
void Mobile::callPerson(std::string num)
{
	//check that number entered is valid or throw exception
	int valid = this->checkNum(num);
	if (valid == -1)
		throw "Cannot dial number.  Not in valid format.  Please enter number in XXX-XXX-XXXX format.";
	else
	{
		bool isInList = false;
		int person = 0;

		//Look through the contacts list for the number.  If number is found, retrieve user name.
		for (int i = 0; i < this->contactSize; i++)
		{
			if (this->contactList[i].number == num)
			{
				isInList = true;
				person = i;
				break;
			}
		}
		//If user exists in contact list, calls the person by name.
		if (isInList)
		{
			std::cout << "Calling: " << this->contactList[person].name << std::endl;
		}
		//If not in the list, just call the number
		else
		{
			std::cout << "Calling: " << num << std::endl;
		}
	}
}
//Overloaded to take a contact and passes the contact's nubmer into the other mehtod
void Mobile::callPerson(Contact c)
{
	this->callPerson(c.number);
}
//Getters
std::string Mobile::getModel()
{
	return this->model;
}
std::string Mobile::getSerial()
{
	return this->serialnumber;
}
std::string Mobile::getphoneNumber()
{
	return this->phoneNumber;
}
//Searches the contact list for a particular name.  If the name is not in the list, throws exception.
//If found, the list is shifted donw to "remove" it from the list.
void Mobile::removeContact(std::string name)
{
	bool found = false;
	//Look through entire list
	for (int i = 0; i < this->contactSize; i++)
	{
		if (this->contactList[i].name == name)
		{
			found = true;
		}
		if (found)
		{
			if (i < this->contactSize - 1)
			{
				this->contactList[i] = this->contactList[i + 1];
			}
		}
	}
	if (found)
		(this->contactSize)--;
	else
		throw "Cannot remove contact from list, non existent.";
}
void Mobile::removeContact(Contact c)
{
	this->removeContact(c.name);
}

std::string Mobile::toString()
{
	return "Model: " + this->model + "\nSerial Number: " + this->serialnumber + "\nPhone's number: " + this->phoneNumber + "\nSim: " + this->simNum;
}