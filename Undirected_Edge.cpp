#include "Undirected_Edge.h"


UndirectedEdge::UndirectedEdge(int from, int to) : Edge(from,to)
{
	pointerToCopy = nullptr;
}

void UndirectedEdge::setCopy(UndirectedEdge* pointerToCopy)
{
	this->pointerToCopy = pointerToCopy;
}


UndirectedEdge* UndirectedEdge::getCopy()
{
	return pointerToCopy;
}