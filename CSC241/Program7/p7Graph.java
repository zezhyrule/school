// Graph class from Walls & Mirrors

import java.util.*;

public class p7Graph
{
	private int numVertices;  // num of vertices in the graph
	private int numEdges;	  // num of edges in the graph

	// For each vertex, we need to keep track of the edges,
	// so for each edge, we need to store the second vertex and
	// the edge weight. This can be done as a <key, value> pair,
	// with the second vertex as the key, and the weight as the
	// value. The TreeMap data structure is used to store a list
	// of these <key, value> pairs for each vertex, accessible
	// as adjList.get(v).
	private Vector<TreeMap<Integer, Integer>> adjList;

	public p7Graph(int n)
	{
	// --------------------------------------------------------
	// Constructor for weighted graph.
	// Precondition: The number of vertices n should be
	// greater than zero.
	// Postcondition: Initializes the graph with n vertices.
	// --------------------------------------------------------
		this.numVertices = n;
		this.numEdges = 0;
		this.adjList = new Vector<TreeMap<Integer, Integer>>();

		for (int i = 0; i < numVertices; i++)
		{
			this.adjList.add(new TreeMap<Integer, Integer>());
		} // end for
	} // end constructor
	
	public int getNumVertices()
	{
	// --------------------------------------------------------
	// Determines the number of vertices in the graph.
	// Precondition: None.
	// Postcondition: Returns the no. of vertices in graph.
	// --------------------------------------------------------
		return this.numVertices;
	} // end getNumVertices

	public int getNumEdges()
	{
	// --------------------------------------------------------
	// Determines the number of edges in the graph.
	// Precondition: None.
	// Postcondition: Returns no. of edges in graph.
	// --------------------------------------------------------
		return this.numEdges;
	} // end getNumEdges

	public int getEdgeWeight(Integer v, Integer w)
	{
	// --------------------------------------------------------
	// Determines the weight of the edge between vertices
	// v and w.
	// Precondition: The edge must exist in the graph.
	// Postcondition: Returns the weight of the edge.
	// --------------------------------------------------------
		return this.adjList.get(v).get(w);
	} // end getEdgeWeight

	public void addEdge(Integer v, Integer w, int wgt)
	{
	// --------------------------------------------------------
	// Adds an edge from v to w with weight wgt to the graph.
	// Precondition: The vertices v and w must exist on graph.
	// Postcondition: An edge from v to w is part of the graph.
	// --------------------------------------------------------

		// Add the edge  to both v's and w's adjacency list
		this.adjList.get(v).put(w, wgt);
		this.adjList.get(w).put(v, wgt);
		numEdges++;
	} // end addEdge

	public void addEdge(p7Edge e)
	{
	// --------------------------------------------------------
	// Adds an edge onto graph.
	// Precondition: The vertices contained within Edge e
	// exist in the graph.
	// Postcondition: Edge e is part of the graph.
	// --------------------------------------------------------
	
		// Extract the vertices and weight from edge e
		Integer v = e.getV();
		Integer w = e.getW();
		int weight = e.getWeight();

		addEdge(v, w, weight);
	} // end addEdge

	public void removeEdge(p7Edge e)
	{
	// --------------------------------------------------------
	// Removes an edge from the graph.
	// Precondition: The vertices contained within Edge e
	// exist in the graph.
	// Postcondition: Edge e is no longer part of the graph.
	// --------------------------------------------------------
	
		// Extract the vertices from edge e
		Integer v = e.getV();
		Integer w = e.getW();

		// Remove the edge from v's and w's adjacency list
		adjList.get(v).remove(w);
		adjList.get(w).remove(v);
		numEdges--;
	} // end removeEdge

	public boolean isConnected(Integer v, Integer w)
	{
	// --------------------------------------------------------
	// Determines if an edge exists between v and w.
	// Precondition: v and w are vertices on the graph.
	// Postcondition: Returns true if edge exists.
	// --------------------------------------------------------
		return adjList.get(v).containsKey(w);
	} // end isConnected

	public p7Edge findEdge(Integer v, Integer w)
	{
	// --------------------------------------------------------
	// Finds the edge connecting v and w.
	// Precondition: The edge exists.
	// Postcondition: Returns the edge with the weight.
	// --------------------------------------------------------
		int wgt = adjList.get(v).get(w);
		return new p7Edge(v, w, wgt);
	} // end findEdge

	private TreeMap<Integer, Integer> getAdjList(Integer v)
	{
	// --------------------------------------------------------
	// Returns the adjacency list for the given vertex.
	// Precondition: The vertex exists in the graph.
	// Postcondition: Returns the associated adjacency list.
	// --------------------------------------------------------
		return this.adjList.get(v);
	} // end getAdjList
} // end p7Graph
