// Filename: p6BinaryTree.java
// Purpose: Reference-based implementation of binary tree
public class p6BinaryTree<T>
{
	private TreeNode<T> root;

	public p6BinaryTree()
	{
		this.root = null;
	} // end default constructor

	public p6BinaryTree(T rootItem)
	{
		this.root = new TreeNode<T>(rootItem);
	} // end constructor

	public p6BinaryTree(T rootItem, p6BinaryTree<T> leftTree, p6BinaryTree<T> rightTree)
	{
		this.root = new TreeNode<T>(rootItem);
		attachLeftSubtree(leftTree);
		attachRightSubtree(rightTree);
	} // end constructor

	public p6BinaryTree(TreeNode<T> rootNode)
	{
		root = rootNode;
	} // end constructor

	public boolean isEmpty()
	{
	// -----------------------------------------------
	// Determines if tree is empty.
	// Precondition: None.
	// Postcondition: Returns true if tree is empty;
	// false if it's not empty.
	// -----------------------------------------------
		return (this.root == null);
	} // end isEmpty

	public void setRootItem(T newItem)
	{
	// -----------------------------------------------
	// Sets the item in the root of the tree.
	// Precondition: Tree exists, newItem is item to be
	// set at root.
	// Postcondition: newItem is set as root item.
	// -----------------------------------------------
		this.root.item = newItem;
	} // end setRootItem

	public T getRootItem()
	{
	// -----------------------------------------------
	// Returns the item in the tree's root.
	// Precondition: The tree isn't empty.
	// Postcondition: Returns the item in the root.
	// -----------------------------------------------
		return this.root.item;
	} // end getRootItem

	public void attachLeft(T newItem)
	{
	// -----------------------------------------------
	// Attaches an item as the left child of the root.
	// Precondition: Tree isn't empty and no left child.
	// Postcondition: newItem is leftChild of root.
	// -----------------------------------------------
		if (!isEmpty() && root.leftChild == null)
			root.leftChild = new TreeNode<T>(newItem);
	} // end attachLeft

	public void attachRight(T newItem)
	{
	// -----------------------------------------------
	// Attaches an item as the right child of the root.
	// Precondition: Tree isn't empty and no right child.
	// Postcondition: newItem is rightChild of root.
	// -----------------------------------------------
		if (!isEmpty() && root.rightChild == null)
			root.rightChild = new TreeNode<T>(newItem);
	} // end attachRight

	public void attachLeftSubtree(p6BinaryTree<T> leftTree)
	{
	// -----------------------------------------------
	// Attaches a tree onto the left of the root.
	// Precondition: Tree isn't empty and no left child.
	// Postcondition: leftTree is attached to root.
	// -----------------------------------------------
		if (!isEmpty() && root.leftChild == null)
		{
			this.root.leftChild = leftTree.root;
			leftTree.root = null; // ensure only one way to enter tree
		} // end if
	} // end attachLeftSubtree

	public void attachRightSubtree(p6BinaryTree<T> rightTree)
	{
	// -----------------------------------------------
	// Attaches a tree onto the right of the root.
	// Precondition: Tree isn't empty and no right child.
	// Postcondition: rightTree is attached to root.
	// -----------------------------------------------
		if (!isEmpty() && root.rightChild == null)
		{
			this.root.rightChild = rightTree.root;
			rightTree.root = null; // ensure only one way to enter tree
		} // end if
	} // end attachRightSubtree

	public p6BinaryTree<T> detachLeftSubtree() throws Exception
	{
	// -----------------------------------------------
	// Remove the left subtree and return it.
	// Precondition: Tree isn't empty and has left child.
	// Postcondition: leftTree is removed and returned.
	// -----------------------------------------------
		if (isEmpty())
		{
			throw new RuntimeException("Exception: empty tree");
		}
		else
		{
			p6BinaryTree<T> leftTree;
			leftTree = new p6BinaryTree<T>(root.leftChild);
			root.leftChild = null;
			return leftTree;
		} // end if
	} // end detachLeftSubtree

	public p6BinaryTree<T> detachRightSubtree()
	{
	// -----------------------------------------------
	// Remove the right subtree and return it.
	// Precondition: Tree isn't empty and has right child.
	// Postcondition: rightTree is removed and returned.
	// -----------------------------------------------
		if (isEmpty())
		{
			throw new RuntimeException("Exception: empty tree");
		}
		else
		{
			p6BinaryTree<T> rightTree;
			rightTree = new p6BinaryTree<T>(root.rightChild);
			root.rightChild = null;
			return rightTree;
		} // end if
	} // end detachRightSubtree

	class TreeNode<T>
	{
		T item;
		TreeNode<T> leftChild;
		TreeNode<T> rightChild;

		public TreeNode(T newItem)
		{
			this.item = newItem;
			this.leftChild = null;
			this.rightChild = null;
		} // end constructor

		public TreeNode(T newItem, TreeNode<T> left, TreeNode<T> right)
		{
			this.item = newItem;
			this.leftChild = left;
			this.rightChild = right;
		} // end constructor
	} // end TreeNode

} // end p6BinaryTree
