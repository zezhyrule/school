#include <iostream>
#include "Box.h"

int main(int argc, char** argv)
{
	Box boxa(1, 2, 3);
	Box boxb = boxa; // calls copy constructor because operator overload
	
	boxa.print();
	boxb.print();

	std::cout << "---------------------\n";

	boxa.height = 4;
	boxa.width = 5;
	*(boxa.length) = 8;

	boxa.print();
	boxb.print();

	std::cout << "---------------------\n";

	Box boxc(2, 3, 2);
	Box boxd = boxb + boxc; // only works because defined overloaded +
							// adds side lengths together

	cout << "Box B:\n";
	boxb.print();
	cout << "Box C:\n";
	boxc.print();
	cout << "Box D:\n";
	boxd.print();

	while (true); // Prevent corruption until fixed.
	return 0;
}
