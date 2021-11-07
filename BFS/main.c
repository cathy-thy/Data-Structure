//ok 
//https://www.programiz.com/dsa/graph-bfs
#include "BFS.h"

int main() {
	GraphADT graph;
	graph = createGraph(6);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 4);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 4);
	addEdge(graph, 3, 4);

	BFS(graph, 0);

	return 0;
}