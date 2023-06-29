#ifndef VERTEX
#define VERTEX

#include <iostream>
using namespace std;

#include "Edge.h"
#include "Undirected_Edge.h"
#include <list>




class Vertex
{
private:
	list<Edge*> neighbours;
	list<Edge*>::iterator pos;

public:
	friend class Graph;
	friend class UndirectedGraph;
	friend class directedGraph;
};




#endif // !Vertex
