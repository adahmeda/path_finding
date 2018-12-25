/*
 * Graph.cpp
 *
 *  Created on: 25.12.2018
 *      Author: aegan123
 */
#include "graph.h"
#include <iostream>
using namespace std;

Graph::Graph(){
	this->graph = new vector<pair<int,int>>;
}
/*
Graph::~Graph(){
	delete graph;
}
*/

void Graph::addEdge(int node1, int node2, int weight){
	graph[node1].push_back(make_pair(node2, weight));
	graph[node2].push_back(make_pair(node1, weight));
}
// Print adjacency list representaion ot graph
void Graph::printGraph(int V)
	{
	    int v, w;
	    for (int u = 0; u < V; u++)
	    {
	        cout << "Node " << u << " makes an edge with \n";
	        for (auto it = graph[u].begin(); it!=graph[u].size(); it++)
	        {
	            v = it->first;
	            w = it->second;
	            cout << "\tNode " << v << " with edge weight ="
	                 << w << "\n";
	        }
	        cout << "\n";
	    }
	}
