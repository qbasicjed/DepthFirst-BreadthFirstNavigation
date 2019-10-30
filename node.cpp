#include "node.h"

node::node(double valueP)
{
	this->value = valueP;

	left = nullptr;
	right = nullptr;
	up = nullptr;
	down = nullptr;
	rightDown = nullptr;
	rightUp = nullptr;
	leftDown = nullptr;
	leftUp = nullptr;
	searchParent = nullptr;

}

node::~node()
{

}

void node::deleteGraph(node * current)
{
	if (current)
	{
		if (current->up)
		{
			deleteGraph(current->up);
		}
		if (current->rightUp)
		{
			deleteGraph(current->rightUp);
		}
		if (current->right)
		{
			deleteGraph(current->right);
		}
		if (current->rightDown)
		{
			deleteGraph(current->rightDown);
		}
		if (current->down)
		{
			deleteGraph(current->down);
		}
		if (current->leftDown)
		{
			deleteGraph(current->leftDown);
		}
		if (current->left)
		{
			deleteGraph(current->left);
		}
		if (current->leftUp)
		{
			deleteGraph(current->leftUp);
		}
	}
}
