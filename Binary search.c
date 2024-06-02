#include <stdio.h>

int main() 
{
    int size, i, key, low, high, mid, flag = 0;
    int arr[size];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter %d elements in sorted order:\n", size);
    for(i = 0; i < size; i++) 
	{
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    low = 0;
    high = size - 1;
    
    while(low <= high) 
	{
        mid = (low + high) / 2;

        if(arr[mid] == key) 
		{
            printf("Element found at position %d.\n", mid + 1);
            flag = 1;
            break;
        } 
		else if(arr[mid] < key) 
		{
            low = mid + 1;
        } 
		else 
		{
            high = mid - 1;
        }
    }

    if(flag == 0) 
	{
        printf("Element not found in the array.\n");
    }

    return 0;
}

