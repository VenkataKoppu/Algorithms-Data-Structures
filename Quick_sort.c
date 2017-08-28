//Author : Venkat
//Cormen lesson 1 : Quick sort working : With pivot element chosen as the last 
//Worst Case: For ascending and descending list O(n2) and contains all same elements: Happens when only one element is after of before the partition
//Average case: Even if the split ratio is 1:999 - nlogn : T(n) = T(k) + T(n-k-1) + theta(n): General notation
//Generally used a lot in conjunction with insertion sort for small inputs - Hybrid sort 
//Due to recursion in the worst case it takes a stack space of S(n):- n entries can be reduced to logn by tail recursion optimization
//Not stable, In-place
//To escape the worst case: we can implement randomized pivot selection, take median of first
//middle and last element as pivot. If the input contans a lot of duplicates ex : 2 1 3 4 5 6 0 6 6 6 : the best way to 
//deal wth this is to use 3 way partitioning
//Can be implemented iteratively using auxillary stack
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

void quick_sort(int a[], int low, int high)
{
	int pivot;
	if(low < high)
	{
		//Find pivot such that its right side has smaller(may or may not be sorted)elements and its left part bigger 
		pivot = partition(a, low, high);
		//Do this recursively which gives the sorted array
		quick_sort(a, low, pivot - 1);
		quick_sort(a, pivot + 1, high);
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
