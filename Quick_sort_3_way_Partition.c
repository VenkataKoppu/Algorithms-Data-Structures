//Author : Venkat
//Cormen lesson 1 : Quick sort with 3-way partitioning done when there are a lot of duplicates- More efficient than the traditional approach
//The 3-way partitioning is done by using the Dutch national flag algorithm by dijkstra: single pass: 0(n)

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* This function partitions a[] in three parts
a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
c) a[j..r] contains all elements greater than pivot */

//It uses Dutch National Flag Algorithm
void partition(int a[], int low, int high, int *i, int *j)
{
    // To handle 2 elements
    if(high - low <= 1)
    {
        if(a[high] < a[low])
            swap(&a[high], &a[low]);
        *i = low;
        *j = high;
        return;
    }

    int mid = low;
    int pivot = a[high];
    while (mid <= high)
    {
        if(a[mid] < pivot)
            swap(&a[low++], &a[mid++]);
        else if(a[mid] == pivot)
            mid++;
        else if(a[mid] > pivot)
            swap(&a[mid], &a[high--]);
    }

    //update i and j
    *i = low-1;
    *j = mid; //or high-1
}

// 3-way partition based quick sort
void quick_sort(int a[], int low, int high)
{
    if(low >= high) //1 or 0 elements
        return;

    int i, j, k;
	partition(a, low, high, &i, &j);
    /*
	for(k = 0; k <= high; k++)
    {
        printf(" %d ",a[k]);
    }
    printf("\n");
    printf("i = %d j = %d\n", i, j);
    */
	quick_sort(a, low, i);
    quick_sort(a, j, high);
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
