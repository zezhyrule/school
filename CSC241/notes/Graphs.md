NOTES - 2016/11/22

##Graphs

G = {V,E}

A graph G consists of two sets:

* A set V of vertices (basically nodes).
* A set E of edges (connections between nodes).

A subgraph consists of a subset of a graph's vertices and a subset of its edges.

(G') = {V', E'} if V' is a subset of V and E' is a subset of E

Adjacent vertices: two vertices that are joined by an edge.

Undirected Graph: edges do not indicate a direction. The pair of vertices is
unordered.

Directed Graph (digraph): Each edge is a directed edge.

Path: A sequence of edges that begins at one vertex and ends at another vertex.
May pass through the same vertex more than once.

Simple Path: passed through a vertex only once.

Cycle: a path that begins and ends at the same vertex. Cyclic graphs contain a
cycle. Acyclic graphs do not have a cycle.

A simple cycle is a cycle that doesn't pass through a vertex more than once.

Connected graph: at least one edge connected to each vertex.

Complete graph: an edge from each vertex to every other vertex.

Weighted graph: A graph whose edges have numeric labels.


##ADT Graph

Two options for defining graphs:
* the edges don't contain values
* edges do have weights attached to them


Implementing a Graph

Most common implementations of a graph are adjacency matrix and adjacency list.

A matrix just lists all the vertices and says true or false for whether there's
an edge connecting them. An n by n array such that matrix[i][j] is true if there
is an edge from vertex i to vertex j and false if there is no edge from vertex i
to vertex j. For a weighted graph, instead of 1s and 0s for true and false, the
weight values are placed into the array.
