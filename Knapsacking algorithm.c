#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, int weights[], int values[], int n) 
{
    int i, w;
    int **K = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) 
	{
        K[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) 
	{
        for (w = 0; w <= W; w++) 
		{
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Store the result of Knapsack
    int result = K[n][W];

    // Free memory
    for (i = 0; i <= n; i++) 
	{
        free(K[i]);
    }
    free(K);

    return result;
}

int main() 
{
    int n, W, i;

    // Taking user input for number of items
    printf("Enter the number of objects: ");
    scanf("%d", &n);

    int *values = (int *)malloc(n * sizeof(int));
    int *weights = (int *)malloc(n * sizeof(int));

    // Taking user input for values and weights of items
    printf("Enter the values:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &values[i]);
    }

    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &weights[i]);
    }

    // Taking user input for capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Solving the knapsack problem
    int result = knapsack(W, weights, values, n);
    printf("Maximum value in Knapsack = %d\n", result);

    // Free allocated memory
    free(values);
    free(weights);

    return 0;
}

