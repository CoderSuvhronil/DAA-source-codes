#include <stdio.h>

int main() 
{
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size], i;
    
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) 
	{
        scanf("%d", &arr[i]); // Input elements into the array
    }

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int found = 0; 
    
    for (i = 0; i < size; i++) 
	{
        if (arr[i] == key) 
		{
            printf("Element found at index %d\n", i);
            found = 1;
            break; // Break the loop if the element is found
        }
    }

    if (!found) 
	{
        printf("Element not found in the array\n");
    }

    return 0;
}

