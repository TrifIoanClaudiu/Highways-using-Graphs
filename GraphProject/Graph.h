#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Graph
{
public:
	int nodes;
	int kmtotal;//the total number of kilometres of the highways
	vector<string> cities; //a string with the names of the cities
	vector<vector<int>> adj_Matrix;//the adjacency matrix
	vector<bool> initial;//the value is 0 if there wasn't a highway through the city from the beggining
	//1 otherwise
	vector<int> addHighwayUtils;
	vector<int> minimum;//represents the minimum distance of a city through a highway
	void addHighwayUtilss();
	Graph(int nodes);
	void addAllNewPaths();
	void print();
	void addPath(int source, int dest, int c);
	void floydWarshall();
};

