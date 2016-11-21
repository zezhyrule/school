NOTES

##More Tree Terminology

Root is at level one, with height of zero if it's alone. Child of a root will be
level 2.

Full binary tree: all nodes at a level less than h have two children each. A
full binary tree has no missing nodes. _pg. 569_

Complete binary tree: a tree which is full down to level h-1 with level h filled
from left to right. All nodes with 2 children at level h-1 appear to the left of
any node with only one child at that level. Any node with only one child at
level h-1 appears to the left of all nodes with no children at that level. There
is at most one node with only one child at level h-1 and it is a left child.

##Implementation Strategies for Binary Trees

Just like other ADTs, we have an array-based and a reference-based
implementation. However, there are two different array-based implementations for
a binary tree. 

*Array 1*

Tree node contains data, index to left child, index to right child. Free list is
a list of available nodes. The index of a nonexistent child is -1. See _Figure 11-11_. 

This array implementation works for any type of tree (incomplete, arithmetic
expression, etc.).

*Array 2*

Only used for complete trees. Root at location 0. For any node at position
tree[i], its left child is at tree[2*i+1], its right child is at tree[2*i+2],
and its parent is at tree[(i-1)/2].

This tree is stored by filling in from left to right, top to bottom. Advantages
include the ability to always find any node's parent. Good for heaps, where
complete trees are required and finding the parent is often necessary.

*Reference-Based*

Tree node contains data, pointer to left child, pointer to right child. So each
node contains a TreeNodeData item, and two references to TreeNodes of the
same data type.

##Looking at Program 6

Start with infix: (A+B)*(C+D)

1. Push ( onto stack
2. Add A to postfix string
3. Push + onto stack
4. Add B to postfix string
5. Pop and append down to open paren
6. Push * to stack
7. Push ( to stack
8. Add C to postfix string
9. Push + onto Stack
10. Add D to postfix string
11. Pop and append down to open paren

Postfix: AB+CD+*

Now numerically evaluate the postfix using: A=5, B=2, C=6, D=4

Use a double stack.

1. Push 5 onto stack
2. Push 2 onto stack
3. Push 5 + 2 onto stack
4. Push 6 then 4 onto stack
5. Push 6 + 4 onto stack
6. Push 7 * 10 onto stack

Stack contains 70.

Now build a binary expression tree:

Use a TreeNode stack.

1. Scan postfix from left to right
2. When you encounter an operand, create a tree node, put the value in it, and
give it a null left and right child.
3. Push the reference of the operand node onto the stack.
4. When you encounter an operator, create a node and put the data in it. Then
pop the address off of the stack and attach it to the righthand side of the
operator node. Then pop off one more and make it the lefthand side of the node.
5. push the operator node onto the stack.
6. When finished, only the reference to the root of the tree is left on the
stack.

Now if you use preorder traversal, it will give you a valid prefix expression.

##Binary Search Tree

Recall the discussion on binary trees which exhibit the ordering property (the
data in any given node is greater than that of its left subtree and less than
(or equal to) that of its right subtree). An inorder traversal of such a tree
results in a sorted list.

*Building the Tree*

(Array-based 1)
First input value becomes the root of the tree. Free is incremented by one. For
each value, perform the following recursively: compare to the root. If incoming
value is less than root, take a left branch; otherwise, take a right branch.
When a null value is reached, add the node as the appropriate child.

*Searching and Adding Values*

To search for a value, use the same algorithm. To add a value, use the same
algorithm.

*Deleting a Value*

Remember, we must maintain the ordering property during the deletion process.

Value being deleted is a leaf node: delete the node and modify predecessor's
link.

Value being deleted has only a right subtree: delete the node and copy the right
link field into predecessor's link.

Value has only left subtree: delete the node and copy left link field into
predecessor's link. 

Value being deleted has both a left and right subtree: note that we are deleting
VALUES and not nodes. We must determine which value may be used to replace the
value being deleted. Value immediately preceding deleted value, value
immediately following deleted value. Replace value with its inorder successor
(right subtree, leftmost child). Then delete the node that contained the value.
