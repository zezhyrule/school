// Filename: p4StackP.java
// Purpose: Reference-based implementation of stack
import java.lang.RuntimeException;

public class p4StackP implements p4StackInterface
{
	private Node top;
	private int numOfItems;

	public p4StackP()
	{
	// -----------------------------------------------
	// Default Constructor: Creates empty stack.
	// Precondition: None.
	// Postcondition: An empty stack is created.
	// -----------------------------------------------
		top = null;
	} // end default constructor

	public boolean isEmpty()
	{
	// -----------------------------------------------
	// Determines whether a stack is empty.
	// Precondition: None.
	// Postcondition: Returns true if stack is empty;
	// otherwise returns false.
	// -----------------------------------------------
		return (top == null);
	}	// end isEmpty

	public void push(Object newItem)
	{
	// -----------------------------------------------
	// Adds newItem to top of stack.
	// Precondition: newItem is the item to be added.
	// Postcondition: newItem is on top of stack.
	// -----------------------------------------------
		top = new Node(newItem, top);
		numOfItems++;
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
			Node temp = top;
			top = top.next;
			numOfItems--;
			return temp.item;
		}
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
		return numOfItems;
	} // end getNumOfItems

	class Node
	{
		Object item;
		Node next;

		Node(Object newItem, Node nextNode)
		{
			item = newItem;
			next = nextNode;
		} // end constructor
	} // end class Node
} // end p4StackP
