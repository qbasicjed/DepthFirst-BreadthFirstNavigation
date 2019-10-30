#pragma once
#include "node.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <random>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <functional>

using namespace std;

node * makeGraph();

bool addToMapIfUndiscovered(map<double, bool>& visited, double value);

void BreadthFirst(node * root);
void DepthFirst(node * root);