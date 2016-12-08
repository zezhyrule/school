/*
PROGRAM NAME: Program 7, Graphs
PROGRAMMER:   Charles Davis
CLASS:        CSC 241.001, Fall 2016
INSTRUCTOR:   Dr. D. Dunn
DATE STARTED: December 05, 2016
DUE DATE:     December 08, 2016
REFERENCES:   Data Abstraction & Problem Solving with Java Textbook (graph implementation)

PROGRAM PURPOSE: Takes data about a graph from a file and produces a minimum
				 spanning tree from this data as well as its weight.

VARIABLE DICTIONARY:

	graph, p7Graph - A graph formed from the data file.
	MST, p7Graph - A minimum spanning tree formed from graph.
	v, int - a node or vertex of the graph.
	w, int - a node or vertex of the graph.

ADTs:
	Graph

FILES USED:
	p7.java
	p7Edge.java
	p7Graph.java
	p6.sh

SAMPLE INPUTS:

4
0 2 7
0 3 6
0 1 8
2 3 4
2 1 9
3 1 5
-1
5
0 4 2
0 3 1
2 1 5
2 4 1
4 1 4
4 3 3
3 1 2

SAMPLE OUTPUTS:

Minimum Spanning Tree:
0-3 (6)
3-2 (4)
3-1 (5)

Weight: 15


Minimum Spanning Tree:
0-3 (1)
0-4 (2)
4-2 (1)
3-1 (2)

Weight: 6

---------------------------------------------------------------------
*/
import java.io.*;
import java.util.*;

public class p7
{
	public static void main(String[] args)
	{
		try // try block to catch if file isn't found
		{
			File file = new File("../instr/p7.dat");
			Scanner fileStream = new Scanner(file);

			p7Graph graph;  // a graph
			p7Graph MST;    // a minimum spanning tree
			int numOfNodes; // number of nodes in the graph
			Integer v, w;   // two nodes
			int edgeWeight; // distance of edge between nodes

			boolean done = false; // loop continuation condition
			int input;            // temp variable to check if record is done

			while (fileStream.hasNextInt())
			{
				numOfNodes = fileStream.nextInt();
				graph = new p7Graph(numOfNodes); // create graph
				done = false;
				
				while (!done && fileStream.hasNextInt())
				{
					input = fileStream.nextInt();

					if (input < 0)
					{
					// record is complete
					// create MST from this graph
						MST = createMST(graph);
						//printMST(MST);
						done = true;
					}
					else
					{
					// add an edge with the next three integers
					// representing the two vertices and edge weight
						v = input;
						w = fileStream.nextInt();
						edgeWeight = fileStream.nextInt();

						graph.addEdge(v, w, edgeWeight);
					}
				} // end while
			} // end while

			fileStream.close(); // done with file
		} // end try
		catch (FileNotFoundException e)
		{
			System.out.println(e);
		} // end catch
	} // end main

	public static p7Graph createMST(p7Graph graph)
	{
	// ---------------------------------------------------
	// Creates a minimum spanning tree from a graph.
	// This is an ugly method and I am sorry.
	// Precondition: graph is a weighted, undirected graph.
	// Postcondition: A minimum spanning tree created
	// from graph is returned.
	// ---------------------------------------------------

		int numOfNodes = graph.getNumVertices();
		p7Graph MST = new p7Graph(numOfNodes);
		Vector<Integer> visitedNodes = new Vector<Integer>();
		Vector<Integer> unvisitedNodes = new Vector<Integer>();
		int minEdge = Integer.MAX_VALUE;
		int currentNodeV = 0; // temporary variables to store nodes with smallest path
		int currentNodeW = 0;
		int graphWeight = 0;

		visitedNodes.add(0); // node 0 is visited first

		System.out.println("\nMinimum Spanning Tree:");

		// populate set of unvisited nodes
		for (int i = 1; i < numOfNodes; i++)
		{
			unvisitedNodes.add(i);
		} // end for
		
		while (!unvisitedNodes.isEmpty())
		{
			minEdge = Integer.MAX_VALUE; // reset minimum edge tracker

			// check unvisited nodes for the shortest path
			for (int v : visitedNodes)
			{
				for (int w : unvisitedNodes)
				{
					if (graph.isConnected(v, w))
					{
						if (graph.getEdgeWeight(v, w) < minEdge)
						{
							minEdge = graph.getEdgeWeight(v, w);
							currentNodeV = v;
							currentNodeW = w;
						} // end if
					} // end if
				} // end for
			} // end for
			
			// add minimum edge to MST
			MST.addEdge(currentNodeV, currentNodeW, minEdge);
			System.out.println(currentNodeV + "-" + currentNodeW + " (" + minEdge + ")");
			graphWeight += minEdge;
			// update sets of visited and unvisited nodes
			unvisitedNodes.remove(new Integer(currentNodeW));
			visitedNodes.add(currentNodeW);

		} // end while

		System.out.println("\nWeight: " + graphWeight);
		System.out.println();

		return MST;
	} // end createMST


} // end p6
