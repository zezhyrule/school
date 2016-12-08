// Edge class from Walls & Mirrors

public class p7Edge
{
	private Integer v, w;	// the vertices of the edge
	private int weight;		// the weight of the edge

	public p7Edge(Integer first, Integer second, int edgeWeight)
	{
	// --------------------------------------------------------
	// Constructor. Cretes an edge from v to w with weight edgeWeight.
	// Precondition: None.
	// Postcondition: The edge is created.
	// --------------------------------------------------------
		this.v = first;
		this.w = second;
		this.weight = edgeWeight;
	} // end constructor

	public int getWeight()
	{
	// Returns the edge weight.
		return this.weight;
	} // end getWeight

	public Integer getV()
	{
	// Returns the first vertex of the edge.
		return this.v;
	} // end getV

	public Integer getW()
	{
	// Returns the second vertex of the edge.
		return this.w;
	} // end getW
} // end p7Edge
