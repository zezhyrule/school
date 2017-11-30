// Program Name:	Lab 4
// Programmer:		Charlie Davis
// Instructor:		Dr. Ivancic
// Program Purpose: Create stack and queue objects
//					to test functionality
//
#include <iostream>

#include "ArrayStack.h"
#include "ArrayQueue.h"

int main(int argc, char** argv)
{
	ArrayStack myStack;
	ArrayQueue myQueue;

	myStack.push(20);
	myStack.push(13);
	myQueue.push(3.14);
	myQueue.push(6.28);
	
	std::cout << myStack.pop() << std::endl;
	std::cout << myStack.peek() << std::endl;
	std::cout << myQueue.pop() << std::endl;

	myStack.push(34);

	std::cout << myStack.pop() << std::endl;
	std::cout << myStack.pop() << std::endl;
	std::cout << myQueue.pop() << std::endl;
	// Note: myQueue is empty here
	std::cout << myQueue.pop() << std::endl;

	return 0;
}
