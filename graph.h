#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <utility>

class Graph{

	public:
		Graph();
		void addEdge(int,int,int);
		void printGraph(int);
		~Graph(){delete graph;};
	private:
		std::vector<std::pair<int,int>>* graph;

};
#endif
