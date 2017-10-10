// Lab 2
// Charles Davis

#include<iostream>
#include<fstream>

using std::cout;
using std::string;
using std::ifstream;
using std::endl;

void sortArray(int* numberArray, int numOfElements);
void swapElements(int* num1, int* num2);

int main(int argc, char** argv)
{
	ifstream file; // Input stream for operating on files

	file.open("Lab2.dat");

	// Read line by line
	if (file.is_open())
	{
		int* numberArray;
		int numOfElements;

		// Get size of array
		file >> numOfElements;
		numberArray = new int[numOfElements];

		string trash;
		file >> trash;

		// Fill array with numbers
		for (int i = 0; i < numOfElements; i++)
		{
			file >> numberArray[i];
		}

		sortArray(numberArray, numOfElements);

		for (int i = 0; i < numOfElements; i++)
		{
			cout << numberArray[i];
			cout << endl;
		}

		delete[] numberArray;
	}
	else
	{
		cout << "\nError: File not found.\n" << endl;
	}

	file.close();

	return 0;
}

void sortArray(int* numberArray, int numOfElements)
{
	int smallest;
	for(int j = 0; j < numOfElements - 1; j++)
	{
		smallest = j;

		for(int i = j+1; i < numOfElements; i++)
		{
			if (numberArray[i] < numberArray[smallest])
			{
				smallest = i;
			}
		}
		swapElements((numberArray + j), (numberArray + smallest));
	}
} // end sortArray

void swapElements(int* num1, int* num2)
{
	int temp1, temp2;

	temp1 = *num1;
	temp2 = *num2;

	*num1 = temp2;
	*num2 = temp1;
}
