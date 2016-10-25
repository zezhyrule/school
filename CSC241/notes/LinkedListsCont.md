NOTES - 09/20/16

##Displaying the Contents of a Linked List

curr reference variable references the current node. Initially references the
first node (head). 

To display the data portion of the current node:
`System.out.println(curr.item);` 

To advance the current position to the next node.
`curr = curr.next;`

To display all the data items in a linked list:
`
for (Node curr = head; curr != null; curr = curr.next)
{
	System.out.println(curr.item);
} //end curr
`

To delete node N which `curr` references, set `next` in the node that precedes N
to reference tho node that follows N.
`prev.next = curr.next;`

To return a node that's no longer needed to the system:
`
curr.next=null;
curr = null;
`

##Algorithms

###Traversal of a Linked List

Pre: HEAD (ref to a list)
Post: Traverse a list, possibly to print

1. Have a reference, CUR, reference where HEAD is referencing
2. As long as CUR is not null {advance CUR by one node}:
	a. Print the info from the node where CUR is referencing
	b. Have CUR reference where link field of CUR is referencing

curr = head;
while (curr != null)
	print curr.item;
	curr = curr.next;

###Search of a Linked List

###Insertion into the Front of a Linked List

Pre: HEAD (ref to a list)
	 VALUE to be inserted into a list
Post: Create the node containing VALUE and insert into list in such a way that
the list is sorted in incoming (reverse) order

1. Allocate memory for new node, and have newNode reference it
2. Fill data field(s) of new node and set the link filed to head
3. Head should be changed to reference newNode

###Insertion into End of Linked List

###Insertion into Ordered Linked List
