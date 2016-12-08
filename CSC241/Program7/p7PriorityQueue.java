// -------------------------------------------------------------
// File: p5PriorityQueue.java
// Child class of p5Queue. Reference-based priority queue.
// -------------------------------------------------------------

public class p5PriorityQueue extends p5Queue
{
	public p5PriorityQueue()
	{
		super();
	} // end default constructor

	public void enqueue(char letter, int pVal)
	{
	// ----------------------------------------------------------------------
	// Inserts items into queue according to their priority value.
	// Higher priority values go at the end of the queue.
	// Precondition: Letter is a char, pVal is a positive integer.
	// Postcondition: The item is added to the correct position in the queue.
	// ----------------------------------------------------------------------
		Node newNode = new Node(letter, pVal);

		if (!isEmpty())
		{
			Node curr = back.next;

			if (newNode.number <= curr.number) // item goes at front of queue
			{
				newNode.next = back.next;
				back.next = newNode;
			}
			else if (newNode.number > back.number) // item goes at end of queue
			{
				newNode.next = back.next;
				back.next = newNode;
				back = newNode;
			}
			else // item goes somewhere else inside queue
			{
				while (newNode.number > curr.next.number)
				{
					curr = curr.next;
				}

				newNode.next = curr.next;
				curr.next = newNode;
			} // end if
		}
		else // queue is empty
		{
			newNode.next = newNode;
			back = newNode;	
		} // end if

	} // end enqueue

} // end p5PriorityQueue
