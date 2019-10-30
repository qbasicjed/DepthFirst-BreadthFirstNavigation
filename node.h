#pragma once
struct node
{
public:
	node* left;
	node* leftUp;
	node* up;
	node* rightUp;
	node* right;
	node* rightDown;
	node* down;
	node* leftDown;
	//this pointer points to the node's parent in a searhing function
	node* searchParent;
	double value;

	node(double valueP = 0);
	~node();
	void deleteGraph(node * current);
};