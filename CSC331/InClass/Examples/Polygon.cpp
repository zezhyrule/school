#include <iostream>
#include "Polygon.h"

Polygon::Polygon(double width, double height)
{
	this->width = width;
	this->height = height;
}

void setValues(double width, double height)
{
	this->width = width;
	this->height = height;
}

void printValues()
{
	std::cout << "Width: " << this->width << std::endl;
	std::cout << "Height: " << this->height << std::endl;
}
