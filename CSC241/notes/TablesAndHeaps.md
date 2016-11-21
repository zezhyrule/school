NOTES

##Table Concepts

We have been dealing with "value-oriented" ADTs and their operations (insert a
data item of value x, delete a data item of value x, query a data item of value
x, etc.). 

A table contains several pieces of information, one of which is typically the
search key.

*ADT Table Operations*

Mostly the same, but add determine number of items in a table.

*Implementation*

Most of our previous implementations have been linear and have been either
array-based or pointer-based. Must consider insertion, deletion, retrieval, and
traversal. For a non-linear implementation, use a binary search tree, which is
in general a better choice.
