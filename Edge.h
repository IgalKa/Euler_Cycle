#ifndef EDGE
#define EDGE


class Edge
{
private:
	int from;
	int to;
	bool mark_state;
public:
	Edge(int from, int to); //Edge c'tor
	virtual ~Edge() = default; //Edge d'tor
	int getFrom(); // get from what the vertex the edge is
	int getTo(); // get to what vertex the edge is going
	void setMarkedState(bool value); //changed the status of the edge (marked/unmarked)
	bool getMarkedState(); // return if the edge is marked or not
};



#endif // !EDGE

