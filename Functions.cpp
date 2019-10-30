#include "Functions.h"
#include "node.h"
using namespace std;

node * makeGraph()
{
	//               1
	//             /   \
	//            2,    3
	//            | `-, |
	//            4----'5
	//             \   /
	//               6

	//  1
	node* root = new node(1);

	// 2 <-> 1
	node* current;
	current = new node(2);
	current->rightUp = root;
	root->leftDown = current;

	// 4 <-> 2
	current->down = new node(4);
	current->down->up = current;

	// 3 <-> 1
	current = new node(3);
	current->leftUp = root;
	root->rightDown = current;

	// 5 <-> 3
	current->down = new node(5);
	current->down->up = current;

	// 5 <-> 2
	current->leftUp = root->leftDown;
	root->leftDown = current->leftUp;

	// 5 <-> 4
	current = current->down;//current is changed from 3 to 5
	current->left = root->leftDown->down;
	root->leftDown->down = current->left;

	//6 <-> 5
	current->leftDown = new node(6);
	current->leftDown->rightUp = current;

	//6 <-> 4
	current->left->rightDown = current->leftDown;
	current->leftDown = current->left->rightDown;

	return root;
}

bool addToMapIfUndiscovered(map<double, bool>& visited, double valueP)
{
	//  This code checks the values in the map to see if it exists.
	//  If it does not, it returns true.

	//make iterator.
	map<double, bool>::iterator it;

	//see if the value is there and assign the map location to it.
	it = visited.find(valueP);

	//.end is indicative of not finding the value
	if (it == visited.end())
	{
		//insert into map
		visited[valueP] = 1;
		return true;
	}
	else
	{
		return false;
	}
}

void BreadthFirst(node * root)
{
	//variables
	node * current = root;
	node * propNode = NULL;  //node to be tested before being pushed onto the structure, proposed state node
	
	queue<node*> nodesToExpand;
	
	//map
	map<double, bool> visited;
	map<double, bool>::iterator it;

	//add the root to the map
	addToMapIfUndiscovered(visited, root->value);
	cout << "starting at: " << root->value << endl;

	//searching clockwise
	while (visited.size() < 6)
	{
		//load children into queue
		if (current->up)
		{
			if (addToMapIfUndiscovered(visited, current->up->value))
			{
				current->up->searchParent = current;
				nodesToExpand.push(current->up);
			}
		}
		if (current->rightUp)
		{
			if (addToMapIfUndiscovered(visited, current->rightUp->value))
			{
				current->rightUp->searchParent = current;
				nodesToExpand.push(current->rightUp);
			}
		}		
		if (current->right)
		{
			if (addToMapIfUndiscovered(visited, current->right->value))
			{
				current->right->searchParent = current;
				nodesToExpand.push(current->right);
			}
		}		
		if (current->rightDown)
		{
			if (addToMapIfUndiscovered(visited, current->rightDown->value))
			{
				current->rightDown->searchParent = current;
				nodesToExpand.push(current->rightDown);
			}
		}		
		if (current->down)
		{
			if (addToMapIfUndiscovered(visited, current->down->value))
			{
				current->down->searchParent = current;
				nodesToExpand.push(current->down);
			}
		}		
		if (current->leftDown)
		{
			if (addToMapIfUndiscovered(visited, current->leftDown->value))
			{
				current->leftDown->searchParent = current;
				nodesToExpand.push(current->leftDown);
			}
		}		
		if (current->left)
		{
			if (addToMapIfUndiscovered(visited, current->left->value))
			{
				current->left->searchParent = current;
				nodesToExpand.push(current->left);
			}
		}		
		if (current->leftUp)
		{
			if (addToMapIfUndiscovered(visited, current->leftUp->value))
			{
				current->leftUp->searchParent = current;
				nodesToExpand.push(current->up);
			}
		}		


		//update current
		current = nodesToExpand.front();
		nodesToExpand.pop();

		//display current
		cout << "node: " << current->value << "\twith parent: " << current->searchParent->value << endl;
	}

	//update current
	current = nodesToExpand.front();
	nodesToExpand.pop();

	//display current
	cout << "node: " << current->value << "\twith parent: " << current->searchParent->value << endl;

	return;
}

void DepthFirst(node * root)
{
	//variables
	node * current = root;
	node * propNode = NULL;  //node to be tested before being pushed onto the structure, proposed state node


	stack<node*> nodesToExpand;

	//map
	map<double, bool> visited;
	map<double, bool>::iterator it;

	//add the root to the map
	addToMapIfUndiscovered(visited, root->value);

	nodesToExpand.push(current->up);
	cout << "starting at: " << root->value << endl;

	//searching clockwise
	do
	{
		//load children into queue
		//You'll notice that searchParent assignment is outside the conditional block here.
		//This is so that the current branch has precedence over previous discoveries.
		//For example, 3 would have been branched from 1 after the 1, 2, 4, 6, 5 branch was complete.
		//This would be an issue, since 5 can get directly to 3.
		if (current->up)
		{
			current->up->searchParent = current;
			if (addToMapIfUndiscovered(visited, current->up->value))
			{

				
				nodesToExpand.push(current->up);
			}

		}
		if (current->rightUp)
		{
			current->rightUp->searchParent = current;
			if (addToMapIfUndiscovered(visited, current->rightUp->value))
			{
				
				nodesToExpand.push(current->rightUp);
			}
		}
		if (current->right)
		{
			current->right->searchParent = current;
			if (addToMapIfUndiscovered(visited, current->right->value))
			{
				
				nodesToExpand.push(current->right);
			}
		}
		if (current->rightDown)
		{
			current->rightDown->searchParent = current;
			if (addToMapIfUndiscovered(visited, current->rightDown->value))
			{
				
				nodesToExpand.push(current->rightDown);
			}
		}
		if (current->down)
		{
			current->down->searchParent = current;
			if (addToMapIfUndiscovered(visited, current->down->value))
			{
				
				nodesToExpand.push(current->down);
			}
		}
		if (current->leftDown)
		{

			current->leftDown->searchParent = current;
			if (addToMapIfUndiscovered(visited, current->leftDown->value))
			{
				nodesToExpand.push(current->leftDown);
			}
		}
		if (current->left)
		{current->left->searchParent = current;
			if (addToMapIfUndiscovered(visited, current->left->value))
			{
				
				nodesToExpand.push(current->left);
			}
		}
		if (current->leftUp)
		{current->leftUp->searchParent = current;
			if (addToMapIfUndiscovered(visited, current->leftUp->value))
			{
				
				nodesToExpand.push(current->up);
			}
		}


		//update current
		current = nodesToExpand.top();
		nodesToExpand.pop();

		//display current
		if (current) {
			cout << "node: " << current->value << "\twith parent: " << current->searchParent->value << endl;
		}
	} while (nodesToExpand.size() > 0);

	return;
}