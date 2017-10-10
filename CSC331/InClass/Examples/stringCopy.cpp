// 2017-10-10

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char** argv)
{
	// Can't do this:
	// char* a;
	// because no memory is allocated.

	// Must explicitly declare size
	char a[100];

	cin.getline(a, 100);

	// How to copy contents of a into b?
	// Can't do this:
	// char* b = a;
	// because they both will point to same data
	// and changing a will chang b
	
	// Allocate new pointer with same length as a
	char* b = new char[strlen(a)];
	strcpy(b, a);

	// Changing the array pointed to by a will not change b
	a[0] = 'Z';

	cout << a << endl;
	cout << b << endl;

	return 0;
}
