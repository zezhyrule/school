NOTES - 2016/12/01

##Adjacency Matrix

When building an adjacency matrix, consider if there is an edge between the node
on the row and the first row on each column. If there is an edge, indicate that
with a 1 in the matrix position. A 0 indicates there is no edge between the two
nodes. Other numbers can be used for a weighted graph.

If you add up the number of 1s on a row, it tells you the number of nodes
incident to that edge (degree of node).  The column totals on a weighted
graph indicates the indegree. The row totals indicates the outdegree.

##Adjacency List

An array of linked lists, where each linked list contains the edges to each
node. Every node gets its own element with a list showing the adjacency of each
node.

From wikipedia: "In graph theory and computer science, an adjacency list is a
collection of unordered lists used to represent a finite graph. Each list
describes the set of neighbors of a vertex in the graph."

##Graph Search

*Depth First Search (DFS)*

The start vertex, v, is visited. Select an unvisited vertex, w, adjacent to v.
(typically select based on alphabetical) Call DFS on w. This is a recursive
traversal. If everything has been visited, you'd go back up the recursion.
Continue by visiting every unvisited vertex.

Think of this one as a stack.

*Breadth First Search (BFS)*

BFS differs from DFS in that all unvisited vertices adjacent to v are visited
before going on from there. Depending on the first adjacent one you pick, you
must do everything adjacent to that first one, then everything adjacent to the
second one, and so on.

Think of this one as a queue.

##Spanning Tree

A spanning tree is a tree which is a subgraph of G that includes all of the
vertices of G and enough of its edges to form a tree (no cycles).

A spanning tree of n nodes will have n-1 edges.

You can do a depth first search spanning tree as well to create a spanning tree
from a graph. A breadth-first search is also possible to create this.

##Weighted Graph

A weighted graph is a graph in which each edge has a number assigned to it (a
weight). This number can represent a variety of different things, such as a
number of miles, the names of highways, the price of travel between the
nodes.

For an adjacency matrix, put the values in the connections. For an adjacency
list, make a data item containing the weight of the edge inside the linked list.


##Minimal Spanning Tree 

A minimal spanning tree (MST) is a spanning tree with least weight for a graph.

Use *Prim's Algorithm* to create a MST.

From wikipedia: "Prim's algorithm is a greedy algorithm that finds a minimum
spanning tree for a weighted undirected graph. This means it finds a subset of
the edges that forms a tree that includes every vertex, where the total weight
of all the edges in the tree is minimized. The algorithm operates by building
this tree one vertex at a time, from an arbitrary starting vertex, at each step
adding the cheapest possible connection from the tree to another vertex.

The algorithm may informally be described as performing the following steps:

1. Initialize a tree with a single vertex, chosen arbitrarily from the graph.

2. Grow the tree by one edge: of the edges that connect the tree to vertices not
yet in the tree, find the minimum-weight edge, and transfer it to the tree.

3. Repeat step 2 (until all vertices are in the tree).

In more detail, it may be implemented following the pseudocode below.

1. Associate with each vertex v of the graph a number C[v] (the cheapest cost of a
connection to v) and an edge E[v] (the edge providing that cheapest connection).
To initialize these values, set all values of C[v] to +∞ (or to any number
larger than the maximum edge weight) and set each E[v] to a special flag value
indicating that there is no edge connecting v to earlier vertices.

2. Initialize an empty forest F and a set Q of vertices that have not yet been
included in F (initially, all vertices).

3. Repeat the following steps until Q is empty:
	a. Find and remove a vertex v from Q having the minimum possible value of C[v]
	b. Add v to F and, if E[v] is not the special flag value, also add E[v] to F
	c. Loop over the edges vw connecting v to other vertices w. For each such edge, if
	w still belongs to Q and vw has smaller weight than C[w], perform the following
	steps:
		i. Set C[w] to the cost of edge vw
		ii. Set E[w] to point to edge vw.

4. Return F

" (end wikipedia quote)

*Kruskal's Algorithm*

Take the cost of all of the edges and add them in weighted order, making sure
not to create cycles.

Creates a cycle if both the vertices incident to it are on the tree already.
