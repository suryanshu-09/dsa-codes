#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

struct Graph {
    int numNodes;
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
};

void initGraph(struct Graph* graph, int numNodes) {
    graph->numNodes = numNodes;

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->adjacencyMatrix[src][dest] = weight;
    graph->adjacencyMatrix[dest][src] = weight;
}

int minDistance(int dist[], int visited[], int numNodes) {
    int minDist = INF, minIndex;
    
    for (int v = 0; v < numNodes; v++) {
        if (visited[v] == 0 && dist[v] <= minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

void printPath(int parent[], int dest) {
    if (parent[dest] == -1) {
        printf("%d ", dest);
        return;
    }
    
    printPath(parent, parent[dest]);
    printf("%d ", dest);
}

void dijkstra(struct Graph* graph, int src) {
    int dist[MAX_NODES]; 
    int visited[MAX_NODES];
    int parent[MAX_NODES];

    for (int i = 0; i < graph->numNodes; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < graph->numNodes - 1; count++) {
        int u = minDistance(dist, visited, graph->numNodes);

        visited[u] = 1;
        for (int v = 0; v < graph->numNodes; v++) {
            if (!visited[v] && graph->adjacencyMatrix[u][v] && dist[u] != INF &&
                dist[u] + graph->adjacencyMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->adjacencyMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Shortest paths from node %d:\n", src);
    for (int i = 0; i < graph->numNodes; i++) {
        if (i != src) {
            printf("Node %d: ", i);
            printPath(parent, i);
            printf("Distance: %d\n", dist[i]);
        }
    }
}

int main() {
    struct Graph graph;
    int numNodes, numEdges;
    int srcNode;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    
    initGraph(&graph, numNodes);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    printf("Enter the edges and their weights:\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src, dest, weight);
    }

    printf("Enter the source node: ");
    scanf("%d", &srcNode);

    dijkstra(&graph, srcNode);

    return 0;
}

