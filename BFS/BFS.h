typedef struct nodeCDT* nodeADT;
typedef struct GraphCDT* GraphADT;

nodeADT createNode(int v);
GraphADT createGraph(int vertices);
void addEdge(GraphADT graph, int src, int dest);
void BFS(GraphADT graph, int vertex);



typedef struct queueCDT *queueADT;

typedef int queueElementT;

queueADT EmptyQueue();
void Enqueue(queueADT queue, queueElementT element);
queueElementT Dequeue(queueADT queue);
int QueueLength(queueADT queue);
int QueueIsEmpty(queueADT queue);
