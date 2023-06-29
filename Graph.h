#ifndef GRAPH
#define GRAPH

#include "Vertex.h"


enum Color { WHITE, GREY, BLACK };
const int V1 = 1;

class Graph
{
protected:
	Vertex* vertices;
	int number_Of_Vertices;
	Color* color;

public:
	Graph(int number_of_vertices); //graph c'tor (abstract class)
	virtual ~Graph(); //graph c'tor
	virtual void addEdge(int from, int to) = 0; //abstract
	virtual list<int> findCircuit(int v) = 0; //abstract
	virtual bool checkIfGraphEuler() = 0; //abstract
	virtual void visit(int vertex); // visit implementation using DFS
	virtual list<int> getEulerCircuit(); //if the graph is aulerian, return the aurelian circuit
};

#endif // !GRAPH

