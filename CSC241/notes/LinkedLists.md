NOTES - 09/15/16

Ch. 5   Linked Lists

##Preliminaries

Options for implementing an ADT:
* Array - has a fixed size. Data must be shifted during insertions and
	deletions.
* Linked List - is able to grow in size as needed. Doesn't require shifting of
	items

##Object References and Linked Structures

A problem with arrays is that they have a fixed size. Addition and deletion is
difficult. With pointers (link or reference), an object or variable that stores
the address of some other object, typically a structure. Two pointers can
reference the same object. A pointer can also reference nothing. 

Beware of "dangling pointers". 

Linked structures have individual nodes that hold both the object and the
pointer to the next object in the list.

###Object References

A reference variable contains the location of an object.

Example (using java.lang.Integer class)

`
Integer intRef;
intRef = new Integer(5);
`
*See: Figure 5-2*

As a data field of a class has the default value null. A local reference
variable to a method does not have a default value.

When one reference variable is assigned to another reference variable, both
references then refer to the same object.

`
Integer p, q;
p = new Integer(6);
q = p;				// q and p both reference the same object
`

A reference variable that no longer references any object is marked for garbage
collection. An object that is not referenced in java is marked for garbage
collection, but in other languages it might be left out there.

*See Figure 5-3*

An array of objects is really an array of references to the objects.

Example:

`
Integer[] scores = new Integer[30];
`

Instatiating integer objects for each array reference:

`
scores[0] = new Integer(7);
scores[1] = new Integer(9);
`

Equality operators (== and !=) compare the values of reference variables, not
the objects that they reference. The `equals` method compares objects field by
field. When an object is passed to a method as an argument, the reference to the
object is copied to the method's formal parameter. Reference-based ADT
implementations and data structures use Java references.

###Resizable Arrays

The number of references in a Java array is of a fixed size. A resizable array
is an array that grows and shrinks, but it's really an illusion done by copying
fixed-sized arrays over and over.

##Reference-Based Linked List

A linked list contains nodes that are linked to one another. A node contains
both data and a link to the next item. Access is package-private.

`
package List;
class Node
{
	Object item;
	Node next;
	// constructors, accessors,
	// and mutators ...
} // end class Node
`

*See Figure 5-7*

Using the node class:

`
Node n = new Node (new Integer(6));
Node first = new Node (new Integer(9), n);
`

Data field `next` (next being the reference variable for the second data field
of a node) in the last node is set to `null`. `head` reference variable
references the list's first node. This always exists even when the list is
empty.

`head` reference variable can be assigned `null` without first using `new`.

The following sequence results in a lost node:

`
head = new Node(); // don't really need to use new here
head = null;	   // since we lose the new Node object here
`

*pg. 302 contains practice exercises*

a) `p = new IntegerNode(); // an error because of the constructor`

b) `p = new IntegerNode(1, head)` p --> [1|null]

c) `p = new IntegerNode(1);` p --> [1|null]
   `q = new IntegerNode(3,p);` q --> [3|same obj as p ^]
   `p.next = head;` p --> [1|null]
   `head = q;` head --> same obj as q ^]

d) `x = 3;`
   `p = new IntegerNode(x, head);`
   `q = new IntegerNode(p);` -- this line is the problem
   `head = q;`

e) `IntegerNode curr = head;`
   `while (curr != null) {`
   `	curr.item++;`
   `	curr = curr.next;`
   `}`

f)
