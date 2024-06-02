#include<stdio.h>
#include<stdlib.h>

void merge(int[],int[],int,int,int);
void copy(int *, int *,int,int);

void mergesort(int *a,int l,int r)
{
	int m;
	int k[r-l+1];
	if(l<r)
	{
		m=(l+r)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,k,l,m,r);
		copy(a,k,l,r);
	}
}
void merge(int *a,int *b,int l,int m,int r)
{
	int i,j,k;
	i=l;
	j=m+1;
	k=l;
	while(i<=m && j<=r)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(j<=r)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	while(i<=m)
	{
		b[k]=a[i];
		i++;
		k++;
	}
}

void copy(int a[],int b[],int low,int up)
{
	int i;
	for(i=low;i<=up;i++)
		a[i]=b[i];
}

int main()
{
    int i,n;
    printf("Enter size of the array: ");
    scanf("%d",&n);
     
	int a[n];
	
	printf("Enter %d numbers: ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	
	printf("\n\nThe number in sorted order: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
