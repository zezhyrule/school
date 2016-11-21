NOTES - 2016/11/15

##Search Trees

Recall the efficiency of a binary search tree: may be as inefficient as a
sequential search, but may be as efficient as a binary search (array).

We know that the height of a tree affects the efficiency of the search. What
affects the height of the tree? The order in which the data is added to the tree
and the insertions and deletions to the tree. We will examine several variations
of the search tree (assuming no duplicates). 

We can overcome efficiency problems of binary search trees by "height-balancing"
a tree. A 2-3 tree can improve efficiency by guaranteeing a search path never
exceeds log2(n+1).

##2-3 Trees

Characteristics: every node has room to store 2 data fields (or groups of
fields) - smallitem, largeItem. Every node has room for 3 pointers - leftChild,
midChild, rightChild. Every node has either smallItem with no largeItem, or data
in smallItem which precedes data in largeItem. For any non-leaf node, all data
in leftChild subtree precedes data in smallitem, which precedes data in
midChild subtree; all data in midChild subtree precedes data in largeitem (if it
exists), which precedes data in rightChild subtree. All leaves are at the same
level.

A node with 2 non-empty children is called a 2-node. A node with 3 children is
called a 3-node.
