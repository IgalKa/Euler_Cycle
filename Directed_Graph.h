#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH

#include "Graph.h"


class directedGraph :public Graph
{
public:
	directedGraph(int n); //directed graph c'tor
	virtual void addEdge(int from, int to) override; //adds an edge to the graph
	virtual bool checkIfGraphEuler() override; //checks if the graph have the properties of an aulerian graph
	virtual list<int> findCircuit(int vertex) override; //finds a single cirlce in the graph (may not be simple)
	directedGraph* buildTranspose(); //create the transpose graph of the current graph
	bool isStrongConnected(); // checks if the graph is strongly connected
	bool checkInOutDegrees(); // checks if the outdegree and indegree of each vertex is the same
	void resetColorToWhite(); // reset the colors of the color array to white
	
};






#endif // !DIRECTED_GRAPH

