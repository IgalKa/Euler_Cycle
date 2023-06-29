#include "Undirected_Graph.h"

UndirectedGraph::UndirectedGraph(int n):Graph(n)
{
}

void UndirectedGraph::addEdge(int from, int to)
{
	UndirectedEdge* e1=new UndirectedEdge(from, to);
	UndirectedEdge* e2=new UndirectedEdge(to, from);

	//mutual pointer
	e1->setCopy(e2);
	e2->setCopy(e1);

	vertices[from].neighbours.push_back(e1);

	if (vertices[from].neighbours.size() == 1)
		vertices[from].pos = vertices[from].neighbours.begin();//init pos

	vertices[to].neighbours.push_back(e2);

	if (vertices[to].neighbours.size() == 1)
		vertices[to].pos = vertices[to].neighbours.begin();//init pos
}


bool UndirectedGraph::checkGraphConnected()
{
	//init color array
	for (int i = 1; i < number_Of_Vertices; i++)
		color[i] = WHITE;

	visit(V1);

	//check if there is white vertex left in this graph afte visit
	for (int i = 1; i < number_Of_Vertices; i++)
		if (color[i] == WHITE)
			return false;

	return true;
}


bool UndirectedGraph::checkParityDegrees()
{
	for (int i = 1; i < number_Of_Vertices; i++)
		if (vertices[i].neighbours.size() % 2 != 0)
			return false;

	return true;
}


bool UndirectedGraph::checkIfGraphEuler()
{
	return (checkGraphConnected() && checkParityDegrees());
}


list<int> UndirectedGraph::findCircuit(int vertex)
{
	int current_vertex = vertex, neighbour;
	list<int> circle;
	UndirectedEdge* edge;
	UndirectedEdge* copy_edge;
	list<Edge*>::iterator itrEnd = vertices[current_vertex].neighbours.end();

	circle.push_back(current_vertex);

	while (vertices[current_vertex].pos != itrEnd) //while the current vertex has available edges
	{
		edge = (UndirectedEdge*)(*vertices[current_vertex].pos);
		neighbour = edge->getTo();

		circle.push_back(neighbour); //adding the neighbour vertex to the circle 

		edge->setMarkedState(true);
		copy_edge = edge->getCopy();
		copy_edge->setMarkedState(true);

		do//moving the pos of the current vertex to the next available edge
		{
			++vertices[current_vertex].pos;
		} while (vertices[current_vertex].pos != itrEnd 
			&& (*vertices[current_vertex].pos)->getMarkedState() == true);

		if ((*vertices[neighbour].pos) == copy_edge)
		{
			itrEnd = vertices[neighbour].neighbours.end();

			do //moving the pos of the current neighbour to the next available edge
			{
				++vertices[neighbour].pos;
			} while (vertices[neighbour].pos != itrEnd
				&& (*vertices[neighbour].pos)->getMarkedState() == true);
		}

		current_vertex = neighbour;
		itrEnd = vertices[current_vertex].neighbours.end();
	}

	return circle;
}
