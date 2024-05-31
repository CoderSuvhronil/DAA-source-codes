#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX

// A structure to represent a graph
typedef struct {
    int V;
    int** adjMatrix;
} Graph;

// A utility function to create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->adjMatrix = (int**) malloc(V * sizeof(int*));
    int i, j;
    for (i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*) malloc(V * sizeof(int));
        for (j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = INF;
        }
    }
    return graph;
}

// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int V, Graph* graph) {
	int i;
    printf("Edge \tWeight\n");
    for (i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph->adjMatrix[i][parent[i]]);
    }
}

// A utility function to find the vertex with the minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[], int V) {
    int min = INF, min_index, v;

    for (v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v], min_index = v;
        }
    }

    return min_index;
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(Graph* graph) {
    int V = graph->V;
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST
	int i, v, count;
	
    // Initialize all keys as INFINITE
    for (i = 0; i < V; i++) {
        key[i] = INF, mstSet[i] = false;
    }

    // Always include first 1st vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (v = 0; v < V; v++) {
            // graph->adjMatrix[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph->adjMatrix[u][v] is smaller than key[v]
            if (graph->adjMatrix[u][v] && mstSet[v] == false && graph->adjMatrix[u][v] < key[v]) {
                parent[v] = u, key[v] = graph->adjMatrix[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, V, graph);
}

int main() {
    int V, i, j; // Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    Graph* graph = createGraph(V);

    printf("Enter the adjacency matrix (enter %d for infinity):\n", INF);
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("Edge %d-%d: ", i, j);
            scanf("%d", &graph->adjMatrix[i][j]);
            if (graph->adjMatrix[i][j] == INF) {
                graph->adjMatrix[i][j] = INF;
            }
        }
    }

    primMST(graph);

    for (i = 0; i < V; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}

