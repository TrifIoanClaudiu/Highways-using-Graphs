/*The program tries to create highways through most of the important cities of Romania.
It does this by using the already existent highways, and building from there to the other cities.*/



#include "Graph.h"

int main() {
	int n = 11;
	Graph graph(n);
	graph.addPath(2, 4, 90);
	graph.addPath(3, 4, 200);
	graph.addPath(3, 5, 75);
	graph.addPath(3, 9, 270);
	graph.addPath(9, 10, 220);
	int kmInitial = graph.kmtotal;
	graph.addHighwayUtilss();
	graph.addAllNewPaths();
	graph.kmtotal = (graph.kmtotal - kmInitial);
	graph.print();
	cout << "The total cost for the project will be approximate: " << graph.kmtotal * 3 << " million euros!!" << endl;
	graph.floydWarshall();
	cout << "The shortest distance to get from one city to the other would be: " << endl;
	graph.print();
	/*
	The cities are:
	0-Maramures
	1-Iasi
	2-Cluj
	3-Timisoara
	4-Alba
	5-Sibiu
	6-Galati
	7-Brasov
	8-Craiova
	9-Bucuresti
	10-Constanta*/
}