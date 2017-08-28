//Author : Koppu
//Cormen : Implement binary search
//Complexity: log n
//Has the condition that the array should be pre-sorted

#include <stdio.h>

int binary_search(int a[], int key, int high, int low)
{
	int i, mid;
	while(low <= high)
	{
		mid = low + (high-low)/2; //This is done to prevent overflow for large inputs
		if(a[mid] == key)
			return 1;
		
		if(a[mid] > key )
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

int main(void)
{
	int a[20];
	int key, n, i;
	printf("\nEnter Input Size: ");
	scanf("%d",&n);
	printf("\nEnter Elements: ");
	for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter key: ");
	scanf("%d",&key);
	if(binary_search(a, key, n-1, 0))
	{
		printf("\nItem Found - Search success!");
	}
	else
		printf("\nItem not Found - Search unsuccessful!");
}
