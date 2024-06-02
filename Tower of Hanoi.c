#include<stdio.h>
#include<stdlib.h>

void H_tower(int n, char source, char dest, char aux)
{
	if(n == 1)
	{
		printf("Move disk 1 from source rod %c to dest rod %c\n", n, source, dest);
		return;
	}
	H_tower(n-1, source, aux, dest);
	printf("Move disk %d from source %c to dest %c\n", n, source, dest);
	H_tower(n-1, aux, dest, source);
}

int main()
{
	int n;
	printf("Enter the Number of disks:");
	scanf("%d",&n);
	
	H_tower(n,'A','B','C');
	
	return 0;
}
