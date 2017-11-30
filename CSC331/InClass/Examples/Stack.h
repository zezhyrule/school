#ifndef STACK_H
#define STACK_H

// Define nodes to be used in stack
struct Node
{
	double value;
	Node* next;

	// Constructor
	Node(double value)
	{
		this->value = value;
		next = NULL;
	}
};

class Stack
{
public:

	// Constructor
	Stack();

	// Destructor
	~Stack();

	// Push nodes onto stack
	void push(double value);

	// Pop nodes off of stack and retrieve value
	double pop();

	// Retrieve value on top of stack
	const double peek();

	// Check if stack is empty
	const bool isEmpty();

	// Return number of items in stack
	const int getSize();

	// See if given value is contained in stack
	const bool contains(double value);

	// Print contents of stack
	const void print();

private:

	Node* top; // Pointer to the top item on stack
	int size;
};

#endif // STACK_H
