NOTES - 2016/11/03

Chapter 11 - Trees

##Terminology

General Tree: Set of nodes and connections. *Branches* are toward successors. No
node has more than one predecessor. The *root* is the node that has no
predecessor. Nodes directly connected to the root are called children, and the
root is the parent. Nodes with the same parent are called siblings. The root is
the *ancestor* of all the nodes in the tree. All nodes are *descendants* of the
root.

*Leaf nodes*, or terminal nodes, are nodes with no children (bottom of tree). A
*subtree* is a subset of the tree that also has all the characteristics of the
tree. The tree is divided into *levels*. The root is at level 1. Levels give you
an indication of how far a particular node is from the root. The *height* is the
number of nodes on the longest path. A *path* is the set of branches taken to
access a node from the root. On a simple path, it's the shortest path where
every branch is only crossed once. 

The *degree of a node* is the number of successors (children) it has. The degree
of a tree is the degree of the node that has the highest degree.

##Binary Trees

These provides efficiency in storage and clarity in algorithm. Binary trees
are of degree 2. Therefore, a binary tree has two subtrees, the left and the
right subtree (either of which may be empty).

*Heap Tree*

The heap tree is a binary tree that exhibits the heap property.

Heap Property: The data in any given node is greater than or equal to the data
in its left or right subtrees.

*Binary Search Tree*

Also known as a binary sort tree. This is a type of binary tree that exhibits
the ordering property.

Ordering Property: For any given node, the data contained within is greater than
the data in its left subtree and less than or equal to its right subtree.

*Arithmetic Expression Tree:* Operands are leaves and operators are internal.

##ADT Binary Tree

Overview of Operations:

* Create an empty binary tree.
* Create a one-node binary tree, given an item.
* Create a binary tree, given an item for its root and two binary trees for the
root's subtrees.
* Determine if empty.
* Determine or change the data in the binary tree's root. 
* Attach a left or right child to the root.
* Attach a left or right subtree to the root.
* Detach the left or right subtree of the root.
* Return a copy of the left or right subtree of the root.
* Traverse the tree.

##Traversing a Tree

For a tree, you need to visit each node in the tree to traverse it. There are
three ways of traversing a tree: a preorder traversal, an inorder traversal, and
a postorder traversal (in regards to root).  Always scans from left to right.
Leaves will always be left in order.

Preorder traversal: Root-Left-Right

Inorder traversal: Left-Root-Right

Postorder traversal: Left-Right-Root

Code for traversing a tree:

`
preorder (in binTree:BinaryTree)
{
	if (binTree is not empty)
	{
		visit the root;
		preorder(left subtree);
		preorder(right subtree);

	}
}
`

For inorder and postorder, just move the visit around.

Counting the nodes in a tree _page 637, Problem 19a_ (Dr. Dunn's solution).

`
public int numNodes(BinaryTree tree)
{
	int result;

	if (tree.isEmpty())
		result=0;
	else
		result = 1 + numNodes(tree.getLeftSubtree()) +
				 numNodes(tree.getRightSubtree());
	return result;
}
`
