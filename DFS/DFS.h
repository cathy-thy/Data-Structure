typedef struct nodeCDT* nodeADT;
typedef struct GraphCDT* GraphADT;

nodeADT createNode(int v);
GraphADT createGraph(int vertices);
void addEdge(GraphADT graph, int src, int dest);
void DFS(GraphADT graph, int vertex);