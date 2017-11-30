#include "ArrayStack.h"

// Constructor
ArrayStack::ArrayStack(int capacity)
{
	mCapacity = capacity;
	mStack = new double[mCapacity];
	mTop = 0;
}

// Destructor
ArrayStack::~ArrayStack()
{
	delete[] mStack;
}

// Return size of stack
int ArrayStack::getSize() const
{
	return mTop;
}

// Return total capacity of stack
int ArrayStack::getCapacity() const
{
	return mCapacity;
}

// Is stack empty?
bool ArrayStack::isEmpty() const
{
	if (mTop <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Push a new value onto stack
void ArrayStack::push(double val)
{
	// Check if array is full
	if (mTop >= mCapacity)
	{
		// If full, make array larger
		resizeArray(1);
	}
	mStack[mTop] = val;
	mTop++;
}

// Check the top value of the stack
double ArrayStack::peek() const
{
	if (mTop > 0)
	{
		return mStack[mTop - 1];
	}
	else
	{
		// Error value
		return -10000;
	}
}

// Remove top value from stack and return value
double ArrayStack::pop()
{
	double temp = -10000; // defaulted to error value
	if (mTop > 0)
	{
		temp = mStack[mTop - 1];
		mTop--;
	}

	// If the size of the stack falls below half, make array smaller
	// unless less than 10 elements in stack
	if (mTop < (mCapacity / 2) && mTop > 10)
	{
		resizeArray(-1);
	}

	return temp;
}

// Copy the contents of an array into our stack container
void ArrayStack::copyArray(double* source)
{
	int stop;

	// Check for the smaller array and get the size
	if (arrayLength(source) > arrayLength(mStack))
	{
		stop = arrayLength(mStack);
	}
	else
	{
		stop = arrayLength(source);
	}

	// Copy elements from array into stack
	for (int i = 0; i < stop; i++)
	{
		mStack[i] = source[i];
	}
}

// Resize array. The sign of the integer passed determines
// whether the array should grow (+) or shrink (-)
void ArrayStack::resizeArray(int growth)
{
	// Get temporary container
	double* temp = mStack;

	// Check for expand or condense
	if (growth >= 0)
	{
		mCapacity *= INCREASE_ARRAY;
		mStack = new double[mCapacity];
	}
	else if (growth < 0)
	{
		mCapacity *= DECREASE_ARRAY;
		mStack = new double[mCapacity];
	}

	// New array allocated at new size, so copy those elements over!
	copyArray(temp);
}

// Determine length of array
int ArrayStack::arrayLength(double* array) const
{
	return sizeof(array) / sizeof(array[0]);
}
