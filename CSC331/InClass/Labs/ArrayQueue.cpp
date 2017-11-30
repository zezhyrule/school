#include "ArrayQueue.h"

// Constructor
ArrayQueue::ArrayQueue(int capacity)
: ArrayStack(capacity)
{
}

// Override pop method. Queue pulls from front of list
double ArrayQueue::pop()
{
	double temp = -10000;

	// Remove element if list isn't empty
	if (mTop > 0)
	{
		// Remove the first element in list, then shift elements
		temp = mStack[0];
		shiftQueue();
		mTop--;
	}

	// Resize the array if needed
	if (mTop < (mCapacity / 2) && mTop > 10)
	{
		resizeArray(-1);
	}
	
	return temp;
}

// Override peek method. Return front of list
double ArrayQueue::peek() const
{
	if (mTop > 0)
	{
		return mStack[0];
	}
	else
	{
		return -10000;
	}
}

// Shift all elements to new position once one is removed
void ArrayQueue::shiftQueue()
{
	for (int i = 1; i < mTop; i++)
	{
		mStack[i - 1] = mStack [i];
	}
}
