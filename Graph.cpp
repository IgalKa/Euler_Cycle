#include "Graph.h"

Graph::Graph(int number_of_vertices)
{
	number_Of_Vertices= number_of_vertices + 1;
	vertices = new Vertex[number_of_vertices + 1];
	color = new Color[number_of_vertices + 1];
}


Graph::~Graph()
{
	for (int i = 1; i < number_Of_Vertices; i++)
	{
		for (auto edge : vertices[i].neighbours)
			delete edge;
	}

	delete[] vertices;
	delete[] color;
}

void Graph::visit(int vertex)
{
	int u;
	color[vertex] = GREY;

	for (auto edge : vertices[vertex].neighbours) //for each neighbour of the current vertex
	{
		u = edge->getTo();
		if (color[u] == WHITE)
			visit(u);
	}

	color[vertex] = BLACK;
}


list<int> Graph::getEulerCircuit()
{
	list<int> euler_circle;
	list<int> circle;
	list<int>::iterator current;
	list<int>::iterator itrEnd;
	list<Edge*>::iterator edgeEnd;

	if (checkIfGraphEuler())
	{
		euler_circle = findCircuit(1);
		current = euler_circle.begin();
		itrEnd = euler_circle.end();

		++current;

		while (current != itrEnd) //while there is a vertex in euler_circle with unused edges
		{
			edgeEnd = vertices[*current].neighbours.end();
			if (vertices[*current].pos != edgeEnd) //if the current vertex has available edges
			{
				circle = findCircuit(*current);
				circle.pop_back();
				current = euler_circle.insert(current, circle.begin(), circle.end());//pasting the circle into euler_circle insead of the current vertex
			}
			++current;
		}
	}

	return euler_circle;
}
