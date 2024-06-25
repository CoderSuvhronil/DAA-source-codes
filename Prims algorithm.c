#include<stdio.h>
#include<limits.h>
#define V 5
int G[V][V] =  {
                    {0,2,0,6,0},
                    {2,0,3,8,5},
                    {0,3,0,0,7},
                    {6,8,0,0,9},
                    {0,5,7,9,0}
                };

int main()
{
	int noOfEdges;
  	int status[V];
  	int i,j;
	for(i=0;i<V;i++)
		status[i]=0;
	noOfEdges = 0;
  	status[0] = 1;
  	int x, y;
  	printf("Edge : Weight\n");
	while (noOfEdges < V - 1)
    {
    	int min = INT_MAX;
    	x = 0;
    	y = 0;
    	for (i = 0; i < V; i++)
        {
      		if (status[i])
            {
        		for (j = 0; j < V; j++)
                {
          			if (!status[j] && G[i][j])
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
          			}
        		}
      		}
    	}
    	printf("%d -> %d : %d\n", x, y, G[x][y]);
    	status[y] = 1;
    	noOfEdges++;
}

  return 0;
}
