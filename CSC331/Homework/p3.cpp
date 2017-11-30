#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::string;
using std::endl;

// Implement the functions up here.
void addFile(char** filetable, const int SIZE)
{
	const int MAXCHARS = 100;
	char* userString;
	char* ptr_userString = &*userString;

	cout << "Enter a string fewer than 100 characters:" << endl;

	cin.ignore();
	cin.getline(userString, MAXCHARS);

	// Loop through filetable to find NULL space and place string in that location
	bool filetableFull = true;
	for (int i = 0; i < SIZE; i++)
	{
		if (!filetable[i])
		{
			filetable[i] = ptr_userString;
			filetableFull = false;
			i = SIZE; // Exit loop in crappy way
		}
	}

	cout << endl;

	if (filetableFull == true)
	{
		cout << "Table is full.\n";
	}

} // end addFile

void removeFile(char** filetable, const int SIZE)
{
	int index;

	cout << "Which location (index) do you want to free?\n";

	cin >> index;

	if (index >= 0 && index <= 9)
	{
		if (filetable[index])
		{
			filetable[index] = NULL;
		}
	}
	else
	{
		cout << "Invalid index.\n";
	}

} // end removeFile

void printTableContents(char** filetable, const int SIZE)
{

	cout << "{";

	for (int i = 0; i < SIZE; i++)
	{
		cout << i << ":";

		if (!filetable[i])
		{
			cout << "FREE";
		}
		else
		{
			cout << filetable[i];
		}

		if (i < SIZE - 1)
		{
			cout << ", ";
		}
	}

	cout << "}\n";

} // end removeFile

int main(int argc, char** argv)
{
	const int SIZE = 10;
	char* filetable[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		filetable[i] = NULL;
	}

	cout << "Table created" << endl << endl;

	bool loop = true;
	char choice;
	do
	{
		cout << "-------------------------\n";
		cout << "(A)dd to the table.\n";
		cout << "(R)emove from the table.\n";
		cout << "(D)isplay contents of memory.\n";
		cout << "(E)xit program.\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
			case 'A':
			case 'a':
				//TODO: Implement this function call
				addFile(filetable, SIZE);
				break;
			case 'R':
			case 'r':
			//TODO: Implement this function call
				removeFile(filetable, SIZE);
				break;
			case 'D':
			case 'd':
				//TODO: Implement this function call
				printTableContents(filetable, SIZE);
				break;
			case 'E':
			case 'e':
			default:
				loop = false;
				break;
		}
	} while (loop == true);

	return 0;
}
