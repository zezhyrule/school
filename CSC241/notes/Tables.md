NOTES - 2016/11/15


##Implementation of Tables

*Scenario A: Insertion and Traversal in No Particular Order*

An unsorted order is efficient. Both array-based and reference based tableInsert
operation is O(1).

Array based versus reference based: If a good estimate of the maximum possible
size of the table is not available, a reference based implementation is
preferred. Otherwise, using an Array is good style. 

A binary search tree implementation is not appropriate. It does more work than
the application requires. 

*Scenario B: Retrieval*

In an array-based implementation, binary search can be used if the array is
sorted. For a reference-based implementation, binary search can be performed,
but it is too inefficient to be practical. A binary search of an array is more
efficient than a sequential search of a linked list. Binary search of an array
is O(log n) worst case. Sequential search is O(n).

For frequent retrievals, if the table's max size is known, use a sorted array.
If it's not known, use a binary search tree.

*Scenario C: Insertion, Deletion, Retrieval, and Traversal in Sorted Order*

Two steps are performed by both insertion and deletion. Step 1 is finding the
appropriate position, which is better with the array-based. Step 2 is inserting
or deleting which is easier with a reference-based implementation.

Neither an array or linked list is suitable for both. A binary search tree
implementation combines the best features of both.

##Heaps

Recall the discussion on binary trees which exhibit the heap property: the data
in any given node is greater than that of its left or right subtree. 

The largest value is at the root, known as a maxheap.  (A type of heap in which
the root contains the item with the smallest search key is a minheap.)

Our implementation will be based on maintaining a complete tree.

Heaps are primarily used as priority queues. We are concerned only with removing
the item with the highest priority, located at the root.

##Heap Operations

Insertion:
Add the item to the next available position. Then walk it up the tree until its
parent on the path is greater than it.

Deletion:
Delete the item at the root and reshuffle the remaining nodes by taking the last
node and replacing it at the root (to keep a complete tree). Take the last node
(new root) and walk it down until it's greater than both its children. Swap with
the larger value on its subtrees.

##Heap Sort

Heap sort consists of two phases:

Phase I: Convert a list of numbers to a heap. Create a tree. Process the node
that is the parent of the rightmost node on level h (call walkdown). Move left
on the same level (h-1) and repeat. When leftmost node is reached, move up one
level and process the rightmost node. 

Phase II: Use the heap property to sort the numbers. Call walkdown on the new
root value until it's in its proper place. (after swapping with least value)
