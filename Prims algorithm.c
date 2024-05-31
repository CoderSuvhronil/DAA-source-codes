#include <stdio.h>
#include <stdlib.h>

int n, cost[10][10], nears[10];

void readv() {
    int i, j;
    printf("Enter the number of nodes or vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix of the graph (use 0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if ((cost[i][j] == 0) && (i != j)) {
                cost[i][j] = 999;  // Use a large value to represent infinity
            }
        }
    }
}

void primsalgo() {
    int t[10][2];
    int i, j, k, l, min = 999, u, v, mincost = 0;
    
    // Initialize nears array
    for (i = 1; i <= n; i++) {
        nears[i] = 999;
    }

    // Find the first edge with the minimum cost
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    // Store the first edge in the tree
    t[1][0] = u;
    t[1][1] = v;
    mincost = min;
    nears[u] = nears[v] = 0;

    // Initialize the nears array
    for (i = 1; i <= n; i++) {
        if (nears[i] != 0) {
            if (cost[i][u] < cost[i][v]) {
                nears[i] = u;
            } else {
                nears[i] = v;
            }
        }
    }

    // Construct the rest of the minimum spanning tree
    for (i = 2; i <= n-1; i++) {
        min = 999;
        for (j = 1; j <= n; j++) {
            if (nears[j] != 0 && cost[j][nears[j]] < min) {
                min = cost[j][nears[j]];
                k = j;
            }
        }

        t[i][0] = k;
        t[i][1] = nears[k];
        mincost += min;
        nears[k] = 0;

        for (j = 1; j <= n; j++) {
            if (nears[j] != 0 && cost[j][k] < cost[j][nears[j]]) {
                nears[j] = k;
            }
        }
    }

    printf("The minimum cost of spanning tree is %d\n", mincost);
    printf("The edges of the minimum spanning tree are:\n");
    for (i = 1; i <= n-1; i++) {
        printf("(%d, %d)\n", t[i][0], t[i][1]);
    }
}

int main() {
    readv();
    primsalgo();
    return 0;
}

