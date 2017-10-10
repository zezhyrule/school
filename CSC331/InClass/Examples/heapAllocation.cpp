#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	// "Create new dynamic memory object
	// storing integer value of 9"
	// allocate dynamic memory of primitive type
	int* ptra = new int(9); 

	cout << ptra << endl; // prints address of integer on heap
	cout << *ptra << endl; // prints value stored at location

	// deallocate memory pointed to by pointer
	delete ptra;

	// Create int holding size of array
	int num = 5;

	// Dynamically allocate new array
	int* ptr = new int[num];

	// Delete all memory locations used by the array once done
	delete[] arrayptr;

	return 0;
}
