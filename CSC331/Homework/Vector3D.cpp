#include <iostream>
#include "Vector3D.h"

// Constructor
Vector3D::Vector3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

// Copy Constructor
Vector3D::Vector3D(const Vector3D &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
}

double Vector3D::operator*(const Vector3D &rhs)
{
	double x_temp, y_temp, z_temp;

	// Dot Product
	x_temp = this->x * rhs.x;
	y_temp = this->y * rhs.y;
	z_temp = this->z * rhs.z;

	return x_temp + y_temp + z_temp;
}

Vector3D Vector3D::operator+(const Vector3D &rhs)
{

	double x_temp, y_temp, z_temp;

	// Cross Product
	x_temp = this->y * rhs.z - this->z * rhs.y;
	y_temp = this->x * rhs.z - this->z * rhs.x;
	z_temp = this->x * rhs.y - this->y * rhs.x;

	Vector3D vectorC(x_temp, y_temp, z_temp);

	return vectorC;
}

// Get x value of Vector3D
double Vector3D::getX()
{
	return this->x;
}

// Get y value of Vector3D
double Vector3D::getY()
{
	return this->y;
}

// Get z value of Vector3D
double Vector3D::getZ()
{
	return this->z;
}

// Print dimensions
void Vector3D::printVector()
{
	std::cout << "(" << this->x << ", ";
	std::cout << this->y << ", ";
	std::cout << this->z <<  ")\n";
}
