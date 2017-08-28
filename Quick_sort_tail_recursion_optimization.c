//Author : Venkat
//Cormen lesson 1 : Quick sort with tail recursion optimization to reduce space complexity to O(log n)
//Implicitly done by the compiler but never hurts to learn!

#include <stdio.h>

void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

int partition(int a[], int low, int high)
{
	int j;
	int pivot = a[high];
	int i = (low - 1);
	for(j = low; j <= high - 1; j++)
	{
		if(a[j] <= pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[high]);
	return (i + 1);
}

/* This QuickSort requires O(Log n) auxiliary space in
   worst case. */
void quick_sort(int a[], int low, int high)
{
    while(low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pivot = partition(a, low, high);

        // If left part is smaller, then recur for left
        // part and handle right part iteratively
        if(pivot - low < high - pivot)
        {
            quick_sort(a, low, pivot - 1);
            low = pivot + 1;
        }

        // Else recur for right part
        else
        {
            quick_sort(a, pivot + 1, high);
            high = pivot - 1;
        }
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
	quick_sort(a, 0, n-1);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
