#include <stdio.h>
#include <stdlib.h>
#include "BFS.h"


typedef struct cellT {
	queueElementT element;
	struct cellT *next;
} cellT;

struct queueCDT {
	cellT *head;
	cellT *tail;
};

queueADT EmptyQueue() {
	queueADT queue;
	queue = (queueADT)malloc(sizeof(struct queueCDT));
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}

void Enqueue(queueADT queue, queueElementT element) {
	cellT *cell;
	cell = (cellT *)malloc(sizeof(cellT));
	cell->element = element;
	cell->next = NULL;
	if (QueueIsEmpty(queue))
		queue->head = cell;
	else
		queue->tail->next = cell;
	queue->tail = cell;
}

queueElementT Dequeue(queueADT queue) {
	queueElementT element;
	cellT *cell;
	if (QueueIsEmpty(queue))
		exit(0);
	cell = queue->head;
	element = cell->element;
	queue->head = cell->next;
	free(cell);
	return element;
}

int QueueLength(queueADT queue) {
	cellT *cell;
	int count = 0;
	cell = queue->head;
	while (cell != NULL) {
		count++;
		cell = cell->next;
	}
	return count;
}
int QueueIsEmpty(queueADT queue) {
	return (queue->head == NULL);
	// or: return (QueueLength(queue) == 0);
}


struct nodeCDT
{
	int vertex;
	struct nodeCDT* next;
};

struct GraphCDT
{
	int numVertices;
	int* visited;
	nodeADT* adjLists; // we need int** to store a two dimensional array. Similary, we need struct node** to store an array of Linked lists
};

nodeADT createNode(int v)
{
	nodeADT newNode = (nodeADT)malloc(sizeof(struct nodeCDT));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

GraphADT createGraph(int vertices)
{
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

void addEdge( GraphADT graph, int src, int dest)
{
	// Add edge from src to dest
	nodeADT newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;

	// Add edge from dest to src, for undirected graph 
	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

void BFS(GraphADT graph, int startvertex) {
	queueADT queue = EmptyQueue();
	graph->visited[startvertex] = 1;
	Enqueue(queue, startvertex);

	while (!QueueIsEmpty(queue)) {
		int currentvertex = Dequeue(queue);
		printf("visited %d \n", currentvertex);

		nodeADT temp = graph->adjLists[currentvertex];
		while (temp) {
			int adjvertex = temp->vertex;
			if (graph->visited[adjvertex] == 0) {
				graph->visited[adjvertex] = 1;
				Enqueue(queue, adjvertex);
			}
			temp = temp->next;
		}
	}
}

