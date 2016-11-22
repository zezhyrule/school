// Filename: p6StackP.java
// Purpose: Reference-based implementation of stack
import java.lang.RuntimeException;

public class p6StackP<T>
{
	private Node<T> top;
	private int numOfItems;

	public p6StackP()
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

	public void push(T newItem)
	{
	// -----------------------------------------------
	// Adds newItem to top of stack.
	// Precondition: newItem is the item to be added.
	// Postcondition: newItem is on top of stack.
	// -----------------------------------------------
		top = new Node<T>(newItem, top);
		numOfItems++;
	} // end push

	public T pop() throws RuntimeException
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
			Node<T> temp = top;
			top = top.next;
			numOfItems--;
			return temp.item;
		}
		else
		{	// stack is empty, throw an exception
			throw new RuntimeException("Exception on pop: stack empty");
		} // end if
	} // end pop

	public T peek() throws RuntimeException
	{
	// -----------------------------------------------
	// Retrieves the top of the stack.
	// Precondition: Stack exists.
	// Postcondition: Top is returned. Stack is unchanged.
	// -----------------------------------------------
		if (!isEmpty())
		{
			return top.item;
		}
		else
		{
			throw new RuntimeException("Exception on peek: stack empty");
		} // end if
	} // end peek

	public int getNumOfItems()
	{
	// -----------------------------------------------
	// Returns the number of items in the stack.
	// Precondition: None.
	// Postcondition: The number of items is returned.
	// -----------------------------------------------
		return numOfItems;
	} // end getNumOfItems

	class Node<T>
	{
		T item;
		Node<T> next;

		Node(T newItem, Node<T> nextNode)
		{
			item = newItem;
			next = nextNode;
		} // end constructor
	} // end class Node
} // end p6StackP
