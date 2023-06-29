#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH


#include "Graph.h"

class UndirectedGraph: public Graph
{

public:
	UndirectedGraph(int n); //c'tor
	virtual void addEdge(int from, int to) override; //creates the new edge and its antiparallel edge and adds the two edges to the graph
	virtual bool checkIfGraphEuler() override; //checks if this graph is aulerian
	bool checkGraphConnected(); //checks if this graph connected
	bool checkParityDegrees(); // checks if the degree of all vertices is even
	virtual list<int> findCircuit(int v) override; //finds circuit the begins with v and ends with v
};





#endif // !UNDIRCATED_GRAPH
