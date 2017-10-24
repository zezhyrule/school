#ifndef VECTOR_3D
#define VECTOR_3D

class Vector3D
{
	private:

		// Vector components
		double x, y, z;

	public:

		// Constructor
		Vector3D(double x = 1, double y = 1, double z = 1);

		// Copy Constructor
		Vector3D(const Vector3D &rhs);

		// Overloaded * operator (dot product of vectors)
		double operator*(const Vector3D &rhs);

		// Get x value
		double getX();

		// Get y value
		double getY();

		// Get z value
		double getZ();

		// Print vector components
		void printVector();
};
#endif // !VECTOR_3D
