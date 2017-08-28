//Author : Venkat
//Cormen lesson 1 : Insertion sort working
//Worst Case: O(n2) Best Case: n Descending and Ascending Order Respectively
//Insertion sort is faster than merge sort for small inputs
//Used when almost sorted: Although a heap is faster and has doesnt take extra space like (BST) - n log k
//Stable, inplace, Online in nature
//Although Binary search can be used to quickly find the right position to insert element: the Movements caused nullify the effect
//At any point the left part is always sorted
#include <stdio.h>

void insertion_sort(int a[], int n)
{
	int i, j, key;
	for(i = 1; i < n; i++)
	{
		key = a[i]; //Key is the current card which needs to be placed in its correct position
		j = i - 1;
		while(j >= 0 && a[j] > key)
		{
			a[j+1] = a[j]; //Shift the card Right
			j = j - 1;
		}
		a[j+1] = key;
	}
}

int main(void)
{
	int n, i;
	printf("\nEnter Input Size: ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter Elements\n");
	for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
	insertion_sort(a, n);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
