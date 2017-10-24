// Program Name:	Lab 3
// Programmer:		Charlie Davis
// Instructor:		Dr. Ivancic
// Program Purpose: Perform the dot product operation on
//					two vectors defined by the user

#include <iostream>
#include "Vector3D.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv)
{

	// User values for vectors
	double x_a, y_a, z_a, x_b, y_b, z_b;

	int numberOfVectors = 2;

	Vector3D* vectorArray;

	//cout << "\nEnter the number of vectors: ";
	// cin >> numberOfVectors;
	
	vectorArray = new Vector3D[numberOfVectors];
	
	cout << "\nEnter three values for the first vector: ";

	cin >> x_a;
	cin >> y_a;
	cin >> z_a;

	vectorArray[0] = Vector3D(x_a, y_a, z_a);

	cout << "\nNow enter three values for the second vector: ";

	cin >> x_b;
	cin >> y_b;
	cin >> z_b;

	vectorArray[1] = Vector3D(x_b, y_b, z_b);

	cout << "\nThe dot product of these two vectors is: ";

	double dotProduct = vectorArray[0] * vectorArray[1]; 

	cout << dotProduct;
	cout << endl << endl;

	delete[] vectorArray;
} // end main
