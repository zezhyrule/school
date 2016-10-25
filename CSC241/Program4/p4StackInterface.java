public interface p4StackInterface
{
	public boolean isEmpty();
	// -----------------------------------------------
	// Determines whether a stack is empty.
	// Precondition: None.
	// Postcondition: Returns true if stack is empty;
	// otherwise returns false.
	// -----------------------------------------------

	//public boolean isFull();
	// -----------------------------------------------
	// Determines if a stack is full.
	// Precondition: None.
	// Postcondition: Returns true if stack is full.
	// -----------------------------------------------

	public void push(Object newItem) throws RuntimeException;
	// -----------------------------------------------
	// Adds newItem to top of stack. Throws exception
	// if the insertion is not successful.
	// Precondition: newItem is the item to be added.
	// Postcondition: If insertion is successful,
	// newItem is on the top of the stack.
	// -----------------------------------------------

	public Object pop() throws RuntimeException;
	// -----------------------------------------------
	// Retrieves and removes the top of the stack.
	// Throws exception if deletion is unsuccessful.
	// Precondition: Stack exists.
	// Postcondition: If stack isn't empty, removes
	// top of stack and returns it.
	// -----------------------------------------------

	public int getNumOfItems();
	// -----------------------------------------------
	// Returns the number of items in the stack.
	// Precondition: None.
	// Postcondition: The number of items is returned.
	// -----------------------------------------------
} // end p4StackInterface
