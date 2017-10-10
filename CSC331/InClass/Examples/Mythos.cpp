#include <iostream>
#include "Mythos.h"

using std::string;
using std::cout;
using std::endl;

void Mythos::printMythos()
{
	cout << name << " Size: " << size << " Has Scales: " << hasScales << endl;
}

void Mythos::setName(string n)
{
	name = n;
}

void Mythos::setSize(int s)
{
	size = s;
}

void Mythos::setHasScales(bool h)
{
	hasScales = h;
}
