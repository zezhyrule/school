#ifndef MOBILE_H
#define MOBILE_H
#include <string>

//Structure that holds the information for the contact list
struct Contact
{
	std::string number;
	std::string name;
};

//Class for the phone device
class Mobile
{
public:

	//Constuctor
	Mobile(std::string model = "Generic Model", std::string serialnumber = "111111111111", std::string phoneNumber = "1234567890");

	//desctructor
	~Mobile();

	//Add contact to list
	void addContact(Contact c);
	void addContact(std::string num, std::string name);

	//Add a sim card
	void addSim(std::string sim);

	//Remove a sim card
	void removeSim();

	//Get simcard info
	std::string getSimInfo();

	//Print the contacts list
	void printContacts();

	//Call a particular person
	void callPerson(std::string num);
	void callPerson(Contact c);

	//Getters for info
	std::string getModel();
	std::string getSerial();
	std::string getphoneNumber();

	//Remove a contact from list
	void removeContact(std::string name);
	void removeContact(Contact c);

	//returns all of the phone's information as a string
	std::string toString();

protected:

	//Method to check the number is in a valid format
	int checkNum(std::string number);

	//Strings for phone informaiton
	std::string model, serialnumber, simNum, phoneNumber;
	bool hasSim;

	//array for the contact list
	Contact *contactList;

	//Number of contacts
	int contactSize;

	//max size of contact list
	const int CONTACT_CAPACITY = 255;
};

#endif
