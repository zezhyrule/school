#include <iostream>
#include "Stack.h"

// Constructor
Stack::Stack()
{
	size = 0;
	top = NULL;
}

// Destructor
Stack::~Stack()
{
	Node* temp;

	// Traverse stack and delete pointers
	while (top != NULL)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

// Push nodes onto stack
void Stack::push(double value)
{
	Node* newNode = new Node(value);

	// Set new node's pointer to point at current top item
	if (!isEmpty())
	{
		newNode->next = top;
	}

	// Newly inserted node is now top of stack
	top = newNode;

	// Increment size of stack
	size++;
}

// Pop nodes off of stack and retrieve value
double Stack::pop()
{
	double temp = -15162342;

	if(!isEmpty())
	{
		Node* curr = top;

		temp = top->value;
		top = top->next;
		delete curr;
		
		size--;
	}

	return temp;
}

// Retrieve value on top of stack
const double Stack::peek()
{
	if (isEmpty())
	{
		return -15162342;
	}

	return top->value;
}

// Check if stack is empty
const bool Stack::isEmpty()
{
	return top == NULL;
}

// Return number of items in stack
const int Stack::getSize()
{
	return size;
}

// See if given value is contained in stack
const bool Stack::contains(double value)
{
	bool temp = false;

	if (!isEmpty())
	{
		Node* curr = top;

		while (curr != NULL)
		{
			if (curr->value == value)
			{
				temp = true;
				break;
			}
			curr = curr->next;
		}
	}

	return temp;
}

// Print contents of stack
const void Stack::print()
{
	// Create temp pointer to traverse stack
	Node* curr = top;

	// Traverse stack and print values
	while(curr != NULL)
	{
		std::cout << curr->value << std::endl;

		// Move pointer down through stack
		curr = curr->next;
	}
}
