NOTES - 09/27/2016

Review for Exam 1

Ch. 1-5
* Definitions
* Code (write, read)
* UML diagram/specifications
* ADT concepts
* Linked lists

##Algorithms

Comparing implementations - 
* size - fixed vs dynamic
* storage requirements - dynamic might store more
* access time
* insertions and deletions - fixed is easier to insert and delete

###Variations of Lists

_pg 277_
The types of operations a particular application requires has an effect on the
implementation. If counting the number of nodes in a list is a frequent
operation, the head structure may be modified to include a count. In this case,
head would be a structure rather than a reference variable. 

Many times, insertion in a list is at the end of the list. Here it would be wise
to maintain a tail pointer. The tradeoff is the space required for the tail
pointer versus the time required to traverse the list every time without it.

`
nn = new Node(xx);
nn.next = null;         // make sure to set lastNode.next = null
if (head == null)       // if list has no node
	head = nn;
	tail = nn;
else
	tail.next = nn;
	tail = tail.next;
`

Special cases for lists: if list is empty, if list has one node.

Sometimes we can avoid the complication of inserting and deleting the first node
by using a dummy node. Dr. Dunn doesn't prefer to use dummy nodes because empty
lists aren't that much of a complication. 

In some situations, the last node may actually point to the first node. This is
called a circular linked list. Every node in this type of list has a successor.
The book uses the reference variable `list` instead of head on this list.

Many times we want to traverse a list in both directions. This is known as a
doubly linked list. Nodes in this type of list have two references in them:
`prev` and `next`. head.prev == null and tail.next == null. 

`
// if curr is pointing to the node you want to delete
// in a doubly linked list
curr.next.prev = curr.prev;
curr.prev.next = curr.next;
curr = null;
`

*NEXT LAB*
Some applications require that we have more than one type of link field in a
node. Another example is having one list, but the list may be accessed in more
than one order.

`
CNode - course node
	String CName;
	int Hours;
	char Grade;
	rv nextC;
SNode - student node
	dt item;
	SNode rv nextS;
	CNode rv firstC;
`

##Recursion as a Problem-Solving Technique

Unit II - Chapter 6

Backtracking - the Eight Queens problem
Take a chessboard, with 8 rows and 8 columns.
The queen can attack any piece within its row, its column, or along its
diagonal.
Problem: place 8 queens on a chessboard so that none of them can capture each
other.

Start with First Placement and decide where you can place the second one from
there. Go column by column. If you can't put another one, back up a column and
decide the next place you can place that one and keep going.

Base Case: no more columns to consider. 
Solve the problem with fewer columns

A language is a set of strings of symbols. All programs are strings, but not all
strings are progroms. A compiler follows a set of rules to determine if a string
is part of a language. Grammar is the rules of a language. Syntax diagrams
represent the grammar of the language. A java identifier begins with a letter
and is followed by zero or more letters and digits.

A grammar may be recursive: <identifier> = <letter> 
										   | <identifier><letter> 
										   | <identifier><number>
