// -------------------------------------------------------------
// File: p5Queue.java
// Reference-based implementation of queue ADT.
// -------------------------------------------------------------

public class p5Queue
{
	protected Node back;
	
	public p5Queue()
	{
	// -------------------------------------------------------------
	// Default constructor.
	// Precondition: None.
	// Postcondition: A queue is created.
	// -------------------------------------------------------------
		back = null;
	} // end default constructor
	
	public boolean isEmpty()
	{
	// -------------------------------------------------------------
	// Determines if queue is empty.
	// Precondition: None.
	// Postcondition: Returns true if queue is empty.
	// -------------------------------------------------------------
		return back == null;
	} // end isEmpty

	public void enqueue(char letter, int number)
	{
	// -------------------------------------------------------------
	// Adds a new item to the back of the queue.
	// Precondition: None.
	// Postcondition: A new item is added to the end of the queue.
	// -------------------------------------------------------------
		Node newNode = new Node(letter, number);

		//insert the node
		if (isEmpty())
		{
			newNode.next = newNode;
		}
		else
		{
			newNode.next = back.next;
			back.next = newNode;
		} // end if

		back = newNode; // new node is at back
	} // end equeue

	public Object dequeue() throws Exception
	{
	// -------------------------------------------------------------
	// Retrieve and remove the first item in the queue.
	// Precondition: Queue isn't empty.
	// Postcondition: The first item is removed and returned.
	// -------------------------------------------------------------
		if (!isEmpty())
		{
			// queue is not empty, remove front
			Node first = back.next;
			if (first == back)
			{
				back = null; //if only one item in queue
			}
			else
			{
				back.next = first.next;
			} // end if

			return first.item;
		}
		else
		{
			throw new Exception("Exception on dequeue: queue is empty");
		} // end if
	} // end dequeue

	// dequeueAll()
	public void dequeueAll()
	{
	// -------------------------------------------------------------
	// Removes every item from the queue.
	// Precondition: None.
	// Postcondition: Queue is empty.
	// -------------------------------------------------------------
		back = null;
	} // end dequeueAll

	public void printQueue()
	{
	// -------------------------------------------------------------
	// Traverses and prints queue to screen.
	// Precondition: None.
	// Postcondition: The contents of the queue are printed.
	// -------------------------------------------------------------
		if (!isEmpty())
		{
			Node curr = back.next;
			System.out.print(curr.item + "/" + curr.number);

			curr = curr.next;

			while(curr != back.next)
			{
				System.out.print(" => ");
				System.out.print(curr.item + "/" + curr.number);
				curr = curr.next;
			} // end while
		} // end if
	} // end printQueue

	protected class Node
	{
		protected Object item;
		protected int number;
		protected Node next;

		protected Node(Object item, int number)
		{
		// ---------------------------------------------------------
		// Constructor.
		// Precondition: Item is an object, number is an integer.
		// Postcondition: A new node is created.
		// ---------------------------------------------------------
			this.item = item;
			this.number = number;
			this.next = null;
		} // end constructor
	} // end Node

} // end p5Queue
