#include "Edge.h"

Edge::Edge(int from, int to)
{
	this->from = from;
	this->to = to;
}

void Edge::setMarkedState(bool value)
{
	mark_state = value;
}

bool Edge::getMarkedState()
{
	return mark_state;
}

int Edge::getFrom()
{
	return from;
}
int Edge::getTo()
{
	return to;
}