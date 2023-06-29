#include <iostream>
#include "Helper.h"
using namespace std;


//Program instructions
//1. Enter y if the graph is directed or n if the graph is not directed
//2. Enter an integer, the number of vertices in the graph
//3. Enter an integer, the number of edges in the graph
//4. Enter pairs of integers (ex 1 2) for each edge in the graph, the integers represents what vertices the edge connects (in a connceted graph the the edge is from the first vertex to the second vertex)

int main()
{
	
		Graph* graph = nullptr;
		list<int> euler_circle;
		char is_Directed;
		int num_Of_Vertices, num_Of_Edges, from, to;
		bool validInput = true;
		cout << "Is the graph directed? [y/n] :";
		cin >> is_Directed;
		cout << "Enter number of vertices:";
		cin >> num_Of_Vertices;
		cout << "Enter number of edges:";
		cin >> num_Of_Edges;

		validInput = checkIsNumberOfVerticesValid(num_Of_Vertices);

		if (validInput)
			validInput = checkIsNumberEdgesValid(is_Directed, num_Of_Vertices, num_Of_Edges);

		if (validInput)
		{
			graph = CreateEmptyGraph(is_Directed, num_Of_Vertices);
			validInput= ProccesEdges(graph, num_Of_Vertices, num_Of_Edges);
		}


		if (validInput)
		{
			euler_circle = graph->getEulerCircuit();

			if (euler_circle.size() != 0)
				PrintCircle(euler_circle);

			else
				cout << "The graph is not aulerian" << endl;
		}
		delete graph;
	
}


