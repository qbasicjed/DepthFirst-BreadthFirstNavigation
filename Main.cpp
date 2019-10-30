//                     Breadth-first search and Depth-first search
//              Originated By:  Jordan Dunlap
//               
//
//      Name                  Date                     Nature of Change
//      ****                  ****                     ****************
//   Jordan Dunlap          4/23/2019                  created member variables for node.
//   Jordan Dunlap          4/29/2019                  TBD
//
//


#include "node.h"
#include "Functions.h"

using namespace std;

int main()
{
	cout <<"            1     " << endl <<
		   "          /   \\   " << endl <<
		   "         2,    3  " << endl <<
	       "         | `-, |  " << endl <<
		   "         4----'5  " << endl <<
		   "          \\   /   " << endl <<
		   "            6     " << endl;

	cout << endl << endl << "breadth-first search" << endl << endl;
	node * root = makeGraph();
	BreadthFirst(root);
	root->deleteGraph(root);

	//each search assigns values to searchParent; with a small graph such as this, we can just recreate it from scratch for every search.

	cout << endl << endl << "depth-first search" << endl << endl;
	root = makeGraph();
	DepthFirst(root);
	root->deleteGraph(root);


}
//Note:  Some snippets were adapted from my previously written code.