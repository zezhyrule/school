NOTES - 10/18/16

Chapter 8

## Queues

A queue is a line (like the kind you stand in).
There's a front of the queue and the back (or rear) of queue.

Queues are first-in, first-out (FIFO). 

Adding something to the queue is to enqueue (enqueued to back of queue)
Removing something is to dequeue (dequeued from front of queue).

ADT Queue

Operations:

* Create an empty queue
* Determine whether a queue is empty
* Add a new item to the queue
* Remove from the queue the item that was added earliest
* Remove all the items from a queue
* Retrieve from the queue the item added earliest


Pseudocode for ADT queue operations:

* createQueue()
* isEmpty() > b
* enqueue(newItem)
* dequeue()
* dequeueAll()
* peek()

## Example of Queue

AppendQueue(q, p)
	procedure to append queue `p` onto the end of queue `q`, leaving `p` empty;
	if `q` fills so that excess elements remain in `p`, the procedure calls an
	error-handling procedure.
Pre:
	p and q are queues with values
Post:
	q is a revised queue that contains the elements originally in q followed by
	those in queue `p`

Algorithm:

	if not p.isEmpty() then
		if q.isFull() then
			QueueIfFullError
	else
		item = p.dequeue()
		q.enqueue(item)
		AppendQueue(q, p)


Recognizing Palindromes

To recognize a palindrome, a queue can be used in conjunction with a stack. A
stack can be used to reverse the order of occurrences. A queue can be used to
preserve tho order of occurrences.

## Implementations of the ADT Queue

A queue can have either an array-based implementation or a referenced-based
implementation.

A linear linked list would have two external references: one to the front and
one to the back. It's also possible to have a circular linked list with
only one external reference to the back of the list where back.next points
to the front of the list.

An array can also be used to implement a queue.

Index of the front element, called front
Index of back element, called back

Rightward drift can cause an array-based implementation to become full, even
though the queue should have more space. A circular array can eliminate this
situation. This creates a problem in terms of determining if the queue is full
or empty. Solution: maintain a count of elements. Max elements is MAX_QUEUE-1.

You can't do back = back + 1, because it would be out of bounds if it back is at
MAX_QUEUE-1. What you can do is back = (back + 1) % MAX_QUEUE.

## Comparing Implementations

All of the implementations of the ADT Queue are either array based or referenced
based. A statically allocated array prevents the enqueue operations from adding
an item to the queue if the array is full. A resizable array or a referenced
based array has no size restrictions. A linked-list is more efficient. 

## Summary of Position-Oriented ADTs

Position-oriented ADTs include the list, stack, and queue. In lists, all
positions can be accessed, but with queues and stacks, only the end positions
are accessible. 

Stacks and queues are very similar. 

The definition of the queue operations gives the ADT queue FIFO behavior. A
reference-based implementations of a queue uses either a circular linked list or
a linear linked list with a head reference and a tail reference. An array-based
implementation of a queue is prone to rightward drift, but circular array fixes
this. 
