#include <stdio.h>
#include <stdlib.h>
#include "DFS.h"

struct nodeCDT{
    int vertex;
    struct nodeCDT* next;
};

struct GraphCDT{
	int numVertices;
	int* visited;
	nodeADT* adjLists; // we need int** to store a two dimensional array. Similary, we need struct node** to store an array of Linked lists
};

nodeADT createNode(int v){
	nodeADT newNode = (nodeADT)malloc(sizeof(struct nodeCDT));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

GraphADT createGraph(int vertices){
	GraphADT  graph = (GraphADT) malloc(sizeof(struct GraphCDT));
	graph->numVertices = vertices;

	graph->adjLists = (nodeADT*)malloc(vertices * sizeof(struct nodeCDT*));

	graph->visited = malloc(vertices * sizeof(int));

	int i;
	for (i = 0; i < vertices; i++) {
		graph->adjLists[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}

void addEdge(GraphADT graph, int src, int dest){
	// Add edge from src to dest
	nodeADT newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;

	// Add edge from dest to src, for undirected graph 
	// newNode = createNode(src);
	// newNode->next = graph->adjLists[dest];
	// graph->adjLists[dest] = newNode;
}

void DFS(GraphADT graph, int startvertex) {
    nodeADT adjList = graph->adjLists[startvertex];
    nodeADT temp = adjList;
    graph->visited[startvertex] = 1;
    printf("visited %d \n", startvertex);

    while (temp != NULL){
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex]==0){
           DFS(graph, connectedVertex); 
        }
        temp = temp->next;
    }
}
