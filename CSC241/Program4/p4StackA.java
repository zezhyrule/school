// Filename: p4StackA.java
// Purpose: Array-based implementation of stack

public class p4StackA implements p4StackInterface
{
	final int MAX_STACK = 10; // max size of stack
	private Object items[];
	private int top;

	public p4StackA()
	{
	// -----------------------------------------------
	// Default Constructor: Creates empty stack.
	// Precondition: None.
	// Postcondition: An empty stack is created.
	// -----------------------------------------------
		items = new Object[MAX_STACK];
		top = -1;
	} // end default constructor

	public boolean isEmpty()
	{
	// -----------------------------------------------
	// Determines whether a stack is empty.
	// Precondition: None.
	// Postcondition: Returns true if stack is empty;
	// otherwise returns false.
	// -----------------------------------------------
		return (top < 0);
	}	// end isEmpty

	public boolean isFull()
	{
	// -----------------------------------------------
	// Determines if a stack is full.
	// Precondition: None.
	// Postcondition: Returns true if stack is full.
	// -----------------------------------------------
		return (top == MAX_STACK-1);
	} // end isFull

	public void push(Object newItem) throws RuntimeException
	{
	// -----------------------------------------------
	// Adds newItem to top of stack. Throws exception
	// if the insertion is not successful.
	// Precondition: newItem is the item to be added.
	// Postcondition: If insertion is successful,
	// newItem is on the top of the stack.
	// -----------------------------------------------
		if (!isFull()) // if the stack isn't full
		{
			items[++top] = newItem; // increment top and add
		}						    // newItem to that index
		else
		{   // stack is full, throw an exception
			throw new RuntimeException("Exception on push: stack full");
		} // end if
	} // end push

	public Object pop() throws RuntimeException
	{
	// -----------------------------------------------
	// Retrieves and removes the top of the stack.
	// Throws exception if deletion is unsuccessful.
	// Precondition: Stack exists.
	// Postcondition: If stack isn't empty, removes
	// top of stack and returns it.
	// -----------------------------------------------
		if (!isEmpty()) // if the stack isn't empty
		{
			return items[top--]; // return the item at top
		}						 // and decrement top
		else
		{	// stack is empty, throw an exception
			throw new RuntimeException("Exception on pop: stack empty");
		} // end if
	} // end pop

	public int getNumOfItems()
	{
	// -----------------------------------------------
	// Returns the number of items in the stack.
	// Precondition: None.
	// Postcondition: The number of items is returned.
	// -----------------------------------------------
		return (top+1); // number of items is 1 greater than top index
	} // end getNumOfItems
} // end p4StackA
