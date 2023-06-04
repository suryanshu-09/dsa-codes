#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 20
#define MAX_VERTICES 20

struct Edge {
    int source, destination, weight;
};

struct Graph {
    int numVertices, numEdges;
    struct Edge* edges[MAX_EDGES];
};

struct Graph* createGraph(int numVertices, int numEdges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    int i;
    for (i = 0; i < numEdges; i++) {
        graph->edges[i] = (struct Edge*)malloc(sizeof(struct Edge));
    }
    return graph;
}

void swap(struct Edge* a, struct Edge* b) {
    struct Edge temp = *a;
    *a = *b;
    *b = temp;
}

void sortEdges(struct Graph* graph) {
    int i, j;
    for (i = 0; i < graph->numEdges - 1; i++) {
        for (j = 0; j < graph->numEdges - i - 1; j++) {
            if (graph->edges[j]->weight > graph->edges[j + 1]->weight) {
                swap(graph->edges[j], graph->edges[j + 1]);
            }
        }
    }
}

int find(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        return vertex;
    }
    return find(parent, parent[vertex]);
}

void unionSet(int parent[], int x, int y) {
    int xSet = find(parent, x);
    int ySet = find(parent, y);
    parent[xSet] = ySet;
}

void kruskalMST(struct Graph* graph) {
    struct Edge* result[MAX_VERTICES];
    int parent[MAX_VERTICES];
    int i, j;
    for (i = 0; i < graph->numVertices; i++) {
        parent[i] = -1;
    }

    sortEdges(graph);

    int edgeCount = 0;
    i = 0;
    while (edgeCount < graph->numVertices - 1) {
        struct Edge* currentEdge = graph->edges[i];
        int sourceSet = find(parent, currentEdge->source);
        int destSet = find(parent, currentEdge->destination);

        if (sourceSet != destSet) {
            result[edgeCount++] = currentEdge;
            unionSet(parent, sourceSet, destSet);
        }
        i++;
    }

    printf("Minimum Spanning Tree (Kruskal's Algorithm):\n");
    for (i = 0; i < edgeCount; i++) {
        printf("%d - %d \tWeight: %d\n", result[i]->source, result[i]->destination, result[i]->weight);
    }
}

int main() {
    int numVertices = 6;
    int numEdges = 8;
    struct Graph* graph = createGraph(numVertices, numEdges);

    graph->edges[0]->source = 0;
    graph->edges[0]->destination = 1;
    graph->edges[0]->weight = 4;

    graph->edges[1]->source = 0;
    graph->edges[1]->destination = 2;
    graph->edges[1]->weight = 3;

    graph->edges[2]->source = 1;
    graph->edges[2]->destination = 2;
    graph->edges[2]->weight = 1;

    graph->edges[3]->source = 1;
    graph->edges[3]->destination = 3;
    graph->edges[3]->weight = 2;

    graph->edges[4]->source = 2;
    graph->edges[4]->destination = 3;
    graph->edges[4]->weight = 4;

    graph->edges[5]->source = 3;
    graph->edges[5]->destination = 4;
    graph->edges[5]->weight = 2;

    graph->edges[6]->source = 4;
    graph->edges[6]->destination = 5;
    graph->edges[6]->weight = 6;

    graph->edges[7]->source = 2;
    graph->edges[7]->destination = 5;
    graph->edges[7]->weight = 5;

    kruskalMST(graph);

    return 0;
}

