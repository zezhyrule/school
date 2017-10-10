#include <iostream>
#include "Mythos.h"

int main(int argc, char** argv)
{
	Mythos frank;

	frank.setName("Frank");
	frank.setSize(2);
	frank.setHasScales(true);

	frank.printMythos();

	return 0;
}
