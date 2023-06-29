#include "Helper.h"

bool ProccesEdges(Graph* graph,int num_Of_Vertices, int num_Of_Edges)
{
	bool validInput=true;
	int from, to;
	cout << "Enter the edges in the following format : [From vertex] [To vertex]\n";
	for (int i = 0; i < num_Of_Edges && validInput; i++)
	{
		cout << "Enter edge number ";
		cout << i + 1 << ":";
		cin >> from;
		cin >> to;
		if (checkIsValidEdge(from,to,num_Of_Vertices))
			graph->addEdge(from, to);
		else
		{
			cout << "invalid input" << endl;
			validInput = false;
		}
	}
	return validInput;
}


bool checkIsValidEdge(int from, int to, int num_Of_Vertices)
{
	return ((from >= 1 && from <= num_Of_Vertices) && (to >= 1 && to <= num_Of_Vertices));
}


bool checkIsNumberEdgesValid(int is_Directed,int num_Of_Vertices,int num_Of_Edges)
{
	bool validInput = true;
	switch (is_Directed)
	{
	case 'y':
		if (num_Of_Edges < 0 || num_Of_Edges > (num_Of_Vertices * (num_Of_Vertices - 1)))
		{
			cout << "invalid input";
			validInput = false;
		}
		break;
	case 'n':
		if (num_Of_Edges < 0 || num_Of_Edges > (num_Of_Vertices * (num_Of_Vertices - 1) / 2))
		{
			cout << "invalid input";
			validInput = false;
		}
		break;
	default:
		cout << "invalid input";
		validInput = false;
		break;
	}
	return validInput;
}


Graph* CreateEmptyGraph(int is_Directed,int num_Of_Vertices)
{
	Graph* graph=nullptr;
	switch (is_Directed)
	{
	case 'y':
		graph = new directedGraph(num_Of_Vertices);
		break;
	case 'n':
		graph = new UndirectedGraph(num_Of_Vertices);
		break;
	default:
		break;
	}
	return graph;
}

void PrintCircle(list<int> euler_circle)
{
	int count = 1;
	cout << "The graph is aulerian" << endl;
	cout << "(";
	for (auto v : euler_circle)
	{
		cout << v;
		if (count != euler_circle.size())
			cout << ",";
		count++;
	}
	cout << ")";
}

bool checkIsNumberOfVerticesValid(int num_Of_Vertices)
{
	bool isValid = true;
	if (num_Of_Vertices <= 0)
	{
		cout << "invalid input";
		isValid = false;
	}

	return isValid;
}