#ifndef UNDIRECTED_EDGE
#define UNDIRECTED_EDGE
#include "Edge.h"


class UndirectedEdge : public Edge
{
private:
	UndirectedEdge* pointerToCopy;
public:
	UndirectedEdge(int from, int to); //c'tor
	void setCopy(UndirectedEdge* pointerToCopy); //sets the pointer to the antiparallel edge
	UndirectedEdge* getCopy(); //returns the pointer to the antiparallel edge
};














#endif // !UNDIRECTEDEDGE

