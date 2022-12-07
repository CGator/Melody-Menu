#pragma once
#include <vector>
#include <utility>
#include <string>
#include <map>
#include "Music.h"
#include "GraphNode.h"
using namespace std;


class Graph {
	map<string, vector<Music*>> adjList;
	unsigned int length = 0;
public:
	Graph();
	void insert(Music* x);

	vector<Music*> search(int type, string input);
};
