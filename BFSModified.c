#include<stdio.h>
/*int main()
{
	int n,i,j,v1,v2;
	char ans;
	printf("Enter number of vertices ");
	scanf("%d",&n);
	if(n==1)
	{
		printf("Graph is possible but can't have adjacency matrix ");
		return 0;
	}
	if(n<=0)
	{
		printf("Graph can't be drawn\n");
		return 0;
	}
	int adj[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			adj[i][j]=0;
	do
	{
		printf("Enter the vertices to have an edge ");
		scanf("%d%d",&v1,&v2);
		if(v1<1 || v2<1 || v1>n || v2>n)
			printf("Invalid Vertex\n");
		else if(v1==v2)
			printf("Self loop is not allowed\n");
		else if(adj[v1-1][v2-1] == 1)
			printf("The edge already exists\n");
		else
			adj[v1-1][v2-1] = adj[v2-1][v1-1] = 1;
		printf("Enter another edge ? ");
		fflush(stdin);
		ans=getchar();
	}
	while(ans=='Y' || ans=='y');
	printf("The adjacency matrix is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%-4d",adj[i][j]);
		printf("\n");
	}
}*/
void bfs(int);
int a[7][7]={
			{0,1,0,1,1,0,0},
			{1,0,1,0,0,0,0},
			{0,1,0,0,1,0,1},
			{1,0,0,0,1,0,0},
			{1,0,1,1,0,1,0},
			{0,0,0,0,1,0,1},
			{0,0,1,0,0,1,0}
			};
int main()
{
	int i,j;
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
			printf("%d  ",a[i][j]);
		printf("\n");
	}
	bfs(7);

	return 0;
}
void bfs(int n)
{
     int q[n],f,r,i=0,j;
     f=r=-1;
     static int s[7];
	do
	{
		if(f==-1)
		{
			f=r=0;
			q[f]=i;
			s[i]=1;
		}
		else
		{
			i=q[f];
		}
		for(j=0;j<7;j++)
		{
			if (a[i][j]==1)
			{
				if(s[j]==0)
				{
					q[++r]=j;
					s[j]=1;
				}
			}
		}
		printf("%d ",q[f]);
		s[f]=2;
		if(f==r)
			f=r=-1;
		else
			f++;
		//i++;
	}
	while(f!=-1);
}
