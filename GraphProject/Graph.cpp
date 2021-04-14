#include "Graph.h"


void Graph::addHighwayUtilss()
{
	int dist;
	for (int i = 0; i < nodes; i++) {
		if (initial[i] == 1) {
			for (int j = 0; j < nodes; j++)
				if (initial[j] == 0) {
					cout << "Give the distance from " << cities[i] << " to " << cities[j] << ":";
					cin >> dist;
					if (dist < minimum[j]) {
						minimum[j] = dist;
						addHighwayUtils[j] = i;
					}
				}
		}
	}//determine the minimum distance through every city who doesn't have a highway initially
	//from a city who had;
	for (int i = 0; i < nodes; i++) {
		if (initial[i] == 0) {
			for (int j = 0; j < nodes; j++)
				if ((initial[j] == 0) && (i != j)) {
					cout << "Give the distance from " << cities[i] << " to " << cities[j] << ":";
					cin >> dist;
					if (dist < minimum[j]) {
						minimum[j] = dist;
						addHighwayUtils[j] = i;
					}
				}
		}
	}//checks if there exists a shorter path from two city that did not had highway initially.
}

Graph::Graph(int nodes) {
	this->nodes = nodes;
	string city;
	ifstream fromFile;
	fromFile.open("Cities.txt");
	for (int i = 0; i < nodes; i++) {
	//	cout << "Give the city on the position " << i << ":";
		fromFile >> city;
		cities.push_back(city);
		initial.push_back(0);
		minimum.push_back(INT_MAX);
		addHighwayUtils.push_back(-1);
	}
	for (int i = 0; i < nodes; i++) {
		vector<int> aux;
		for (int j = 0; j < nodes; j++)
			if (i == j)
				aux.push_back(0);
			else
				aux.push_back(INT_MAX);
		adj_Matrix.push_back(aux);
	}
}

void Graph::addAllNewPaths()
{
	for (int i = 0; i < nodes; i++) {
		if (initial[i] == 0) {
			addPath(i, addHighwayUtils[i], minimum[i]);
		}
	}
}

void Graph::addPath(int i, int j, int c) {
	this->adj_Matrix[i][j] = c;
	this->adj_Matrix[j][i] = c;
	kmtotal = kmtotal + c;
	initial[i] = 1;
	initial[j] = 1;
}

void Graph::print() {
	for (int i = 0; i < this->nodes; i++) {
		for (int j = 0; j < this->nodes; j++)
			if ((this->adj_Matrix[i][j] != INT_MAX) && (i != j))
			{
				cout << cities[i] << "->" << cities[j] << " : ";
				cout << this->adj_Matrix[i][j];
				cout << endl;
			}
	}
}

void Graph::floydWarshall()
{
	for (int k = 0; k < nodes; k++) {
		for (int i = 0; i < nodes; i++) {
			for (int j = 0; j < nodes; j++) {
				if ((this->adj_Matrix[i][k] != INT_MAX) && (this->adj_Matrix[k][j] != INT_MAX))
					this->adj_Matrix[i][j] =
					min(this->adj_Matrix[i][j], this->adj_Matrix[i][k] + this->adj_Matrix[k][j]);
			}
		}
	}

}
