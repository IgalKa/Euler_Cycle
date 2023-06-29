#ifndef HELPER
#define HELPER

#include "Directed_Graph.h"
#include "Undirected_Graph.h"

bool ProccesEdges(Graph* graph, int num_Of_Vertices, int num_Of_Edges);
bool checkIsNumberEdgesValid(int is_Directed, int num_Of_Vertices, int num_Of_Edges);
bool checkIsNumberOfVerticesValid(int num_Of_Vertices);
Graph* CreateEmptyGraph(int is_Directed, int num_Of_Vertices);
bool checkIsValidEdge(int from, int to, int num_Of_Vertices);
void PrintCircle(list<int> euler_circle);

#endif // !HELPER
