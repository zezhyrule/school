#include <iostream>

#include "Mobile.h"

int main(int argc, char** argv)
{
	// Create Mobile object
	std::string model;
	std::string serialNumber;
	std::string phoneNumber;

	std::cout << "Initialize your new cell phone->" << std::endl;
	std::cout << " Enter model: ";
	std::cin >> model;
	std::cout << std::endl;
	std::cout << " Enter serial number: ";
	std::cin >> serialNumber;
	std::cout << std::endl;
	std::cout << " Enter phone number: ";
	std::cin >> phoneNumber;
	std::cout << std::endl;

	Mobile mobile(model, serialNumber, phoneNumber);
	
	// Main loop
	char userInput = '?';
	bool looping = true;
	
	while (looping)
	{
		std::cout << "Enter your command (? for list of commands):" << std::endl;
		std::cout << "> ";

		std::cin >> userInput;

		std::cout << std::endl;

		// Normalize input to uppercase
		userInput = toupper(userInput);

		// Determine action based on input
		if (userInput == 'Q')
		{
			std::cout << "Exiting..." << std::endl;
			looping = false;
		}
		else if (userInput == 'A')
		{
			std::string name;
			std::string num;

			std::cout << "Enter contact name: ";
			std::cin >> name;
			std::cout << std::endl;
			std::cout << "Enter contact number: ";
			std::cin >> num;
			std::cout << std::endl;

			std::cout << "Adding contact..." << std::endl;
			mobile.addContact(num, name);

		}
		else if (userInput == 'R')
		{
			std::string name;

			std::cout << "Enter full name of contact to remove: ";
			std::cin >> name;
			std::cout << std::endl;

			std::cout << "Removing contact..." << std::endl;
			mobile.removeContact(name);

		}
		else if (userInput == 'C')
		{
			mobile.printContacts();
		}
		else if (userInput == 'I')
		{
			std::cout << "Model: " << mobile.getModel();
			std::cout << " Serial: " << mobile.getSerial();
			std::cout << " Phone Number: " << mobile.getphoneNumber();
			std::cout << std::endl;
		}
		else // ? or other character entered, display possible commands
		{
			std::cout << std::endl;
			std::cout << "Enter one of the following characters, or type Q to quit.\n";
			std::cout << "  A - [A]dd a contact" << std::endl;
			std::cout << "  R - [R]emove a contact" << std::endl;
			std::cout << "  C - View list of [C]ontacts" << std::endl;
			std::cout << "  I - View phone [I]nformation" << std::endl;
			std::cout << "  S - Add new [S]IM card" << std::endl;
			std::cout << "  D - [D]elete SIM card" << std::endl;
			std::cout << "  E - [E]nter phone number to call" << std::endl;
			std::cout << "  M - [M]ake a phone call based on contact name" << std::endl;
			std::cout << std::endl;
		}
	} // end main loop
}
