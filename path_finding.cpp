#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void addEdge(vector<pair<int,int>>*,int node1, int node2, int weight);
void printGraph(vector<pair<int,int>>*,int);
void genGraph(vector<pair<int,int>>*,int,bool);
void doExit(char**);

int main(int argc, char* argv[]) {
	bool weighted=false;
	if(argc==2){
		if(string(argv[1])=="-w"){
						weighted=true;
					}else if(string(argv[1])=="-n"){
							weighted=false;
				}else{
					cout<<"Invalid parameter "<<argv[1]<<".\n\n";
					doExit(argv);
				}

	}else{
		doExit(argv);
	}
	srand(time(NULL));
	int size=rand() % 100 + 100;
	vector<pair<int,int>> graph[size];
	genGraph(graph,size,weighted);
	cout<<"Success!\n\n";
	//printGraph(graph,size);
	return 0;
}
void genGraph(vector<pair<int,int>>* graph, int size,bool weighted){
	int weight=0,i=0,node1=0,node2=0;
	//cout<<"graph size = "<<size<<"\n\n";
	//for(int i=0;i<size;i++){
	while(i<size){
		node1=rand()%size;
		node2=rand()%size;
		if(node1<size && node2<size){
			if(weighted){
				weight=rand()%10+20;
				}
			addEdge(graph,node1,node2,weight);
			i++;
		}else{
			continue;
		}
	}
}
// Adds an edge to the graph
void addEdge(vector<pair<int,int>>* graph,int node1, int node2, int weight){
	graph[node1].push_back(make_pair(node2, weight));
	graph[node2].push_back(make_pair(node1, weight));
}
// Print adjacency list representation of graph
void printGraph(vector<pair<int,int>>* graph,int size)
	{
	    int v, w;
	    for (int u = 0; u < size; u++)
	    {
	        cout << "Node " << u << " makes an edge with \n";
	        for(auto it=graph[u].begin();it!=graph[u].end();it++)
	        {
	            v = it->first;
	            w = it->second;
	            cout << "\tNode " << v << " with edge weight = "
	                 << w << "\n";
	        }
	        cout << "\n";
	    }
	}
void doExit(char** argv){
	cout<<"Usage:  "<< argv[0] << " <parameters>.\nParameters are:\n\t-w\tGenerates a weighted graph.\n\t-n\tGenerates a non-weighted graph.\n";
	exit (EXIT_FAILURE);
}
