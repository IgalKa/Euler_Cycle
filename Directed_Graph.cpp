#include "Directed_Graph.h"

directedGraph::directedGraph(int n):Graph(n)
{
}


void directedGraph::addEdge(int from, int to)
{
	Edge* newEdge = new Edge(from, to);
	vertices[from].neighbours.push_back(newEdge);
	if (vertices[from].neighbours.size() == 1)
		vertices[from].pos = vertices[from].neighbours.begin(); //init pos
}

directedGraph* directedGraph::buildTranspose()
{
	directedGraph* gTranspose = new directedGraph(number_Of_Vertices - 1);
	Vertex* currVertex;
	int currsize;
	for (int i = 1; i < number_Of_Vertices; i++)
	{
		currVertex = &vertices[i];
		list<Edge*> ::iterator itrStart = currVertex->neighbours.begin();
		list<Edge*> ::iterator itrEnd = currVertex->neighbours.end();
		while (itrStart != itrEnd)
		{
			gTranspose->addEdge((*itrStart)->getTo(), (*itrStart)->getFrom()); //add transpose edge
			++itrStart;
		}

	}

	return gTranspose;
}




bool directedGraph::isStrongConnected()
{
	bool isConnected = true;
	this->resetColorToWhite();

	visit(1);

	for (int i = 1; i < number_Of_Vertices && isConnected == true; i++) //check if all vertices reached
	{
		if (color[i] == WHITE)
			isConnected = false;
	}

	if (!isConnected)
		return isConnected;

	directedGraph* gTranspose = this->buildTranspose(); //create transpose graph
	gTranspose->resetColorToWhite();
	gTranspose->visit(1); //visit on transpose graph

	for (int j = 1; j < number_Of_Vertices && isConnected == true; j++)//check if all vertices reached in the transpose graph
	{
		if (gTranspose->color[j] == WHITE)
			isConnected = false;
	}

	delete gTranspose;

	return isConnected;
}




bool directedGraph::checkInOutDegrees()
{
	bool correctDegrees = true;
	int* indegree = new int[number_Of_Vertices];
	int* outdegree = new int[number_Of_Vertices];

	for (int i = 1; i < number_Of_Vertices; i++)
	{
		indegree[i] = 0;
		outdegree[i] = 0;
	}

	for (int i = 1; i < number_Of_Vertices; i++)
	{
		list<Edge*> ::iterator itrStart = vertices[i].neighbours.begin();
		list<Edge*> ::iterator itrEnd = vertices[i].neighbours.end();
		outdegree[i] = vertices[i].neighbours.size();

		while (itrStart != itrEnd)
		{
			indegree[(*itrStart)->getTo()]++;
			++itrStart;
		}

	}

	for (int i = 1; i < number_Of_Vertices && correctDegrees == true; i++)
	{
		if (outdegree[i] != indegree[i])
			correctDegrees = false;
	}

	delete[] outdegree;
	delete[] indegree;

	return correctDegrees;
}

list<int> directedGraph::findCircuit(int vertex)
{
	list<int> circuit;
	list<Edge*>::iterator itrEnd;
	int currVertex = vertex;
	int neighbour, currSize;
	circuit.push_back(currVertex);
	currSize = vertices[currVertex].neighbours.size();
	if (currSize == 0) //check if there are edges from the vertex
		return circuit;
	else
		itrEnd = vertices[vertex].neighbours.end();

	while (currSize != 0 && vertices[currVertex].pos != itrEnd) //while there are unused edges
	{
		neighbour = (*(vertices[currVertex].pos))->getTo(); //get the vertex from the unused edge
		++(vertices[currVertex].pos);
		currVertex = neighbour;
		currSize = vertices[currVertex].neighbours.size();
		circuit.push_back(currVertex); //add vertex to the circuit
		if (currSize != 0)
			itrEnd = vertices[currVertex].neighbours.end();
	}

	return circuit;
}

void directedGraph::resetColorToWhite()
{
	for (int i = 1; i < number_Of_Vertices; i++)
	{
		color[i] = WHITE;
	}
}

bool directedGraph::checkIfGraphEuler()
{
	return (checkInOutDegrees() && isStrongConnected());
}