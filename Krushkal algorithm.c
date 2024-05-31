#include <stdio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int i);
int uni(int i, int j);

void main() {
    printf("Enter the Number of vertices:\n");
    scanf("%d", &n);

    printf("\nEnter the Cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {  // Correct the loop bounds
        for (j = 1; j <= n; j++) {  // Correct the loop bounds
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;  // Use a large number to represent infinity
        }
    }

    printf("The Edges of Minimum Cost Spanning Tree are\n");
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {  // Correct the loop syntax
            for (j = 1; j <= n; j++) {  // Correct the loop syntax
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;  // Correct assignment
                    b = v = j;  // Correct assignment
                }
            }
        }
        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("%d edge(%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;  // Set the edge cost to infinity
    }
    printf("\nMinimum Cost = %d\n", mincost);
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;  // Correct return statement
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;  // Correct return statement
}

