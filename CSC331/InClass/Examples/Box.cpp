#include <iostream>
#include "Box.h"

// Constructor
Box::Box(int width, int height, int length)
{
	this->width = width;
	this->height = height;

	this->length = new int;   // Allocate space for length pointer
	*(this->length) = length; // Dereference length ptr and copy val
}

// Copy Constructor
Box::Box(const Box &rhs)
{
	this->width = rhs.width;
	this->height = rhs.height;

	this->length = new int;
	*(this->length) = *(rhs.length);
}

// Destructor
Box::~Box()
{
	delete this->length;
}

Box Box::operator+(const Box &rhs)
{
	Box temp = *this; // calls copy constructor

	temp.width += rhs.width;
	temp.height += rhs.height;
	*(temp.width) += *(rhs.width);
}

// Get Volume of Box
double Box::volume()
{
	int templen = *(this->length);
	return this->width * this->height * templen;
}

// Get surface area of box
double Box::surfaceArea()
{
	int templen = *(this->length);
	int side1 = this->width * templen;
	int side2 = templen * this->height;
	int side3 = this->width * this->height;

	return 2 * (side1 + side2 + side3);
}

// Print dimensions
void Box::print()
{
	std::cout << std::endl;
	std::cout << "W: " << this->width << " ";
	std::cout << "H: " << this->height << " ";
	std::cout << "L: " << *(this->length) << std::endl;
	std::cout << "Volume: " << this->volume() << std::endl;
	std::cout << "Surface Area: " << this->surfaceArea() << std::endl;
}
