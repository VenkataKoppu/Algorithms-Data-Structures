//Author : Venkat
//Cormen lesson 1 : Shell sort working
//Shell sort is a variation of insertion sort: Complexity is still n-squared
//Good Explanation: https://www.youtube.com/watch?v=9J14Pbw_XnY by sedgewick
//In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved.
//The idea of shellSort is to allow exchange of far items. In shellSort, we make the array h-sorted for a large value of h. 
//We keep reducing the value of h until it becomes 1. An array is said to be h-sorted if all sublists of every h’th element is sorted.
//Time complexity of above implementation of shellsort is O(n2). In the above implementation gap is reduce by half in every iteration. 
//There are many other ways to reduce gap which lead to better time complexity. example 3x+1 O(n^3/2) proposed by knuth

#include <stdio.h>

void insertion_sort(int a[], int n)
{
	int i, j, key, gap;
	for(gap = n/2; gap > 0; gap = gap/2)
	{
		for(i = gap; i < n; i++)
		{
			key = a[i]; //Key is the current card which needs to be placed in its correct position
			j = i - gap;
			while(j >= 0 && a[j] > key)
			{
				a[j+gap] = a[j]; //Shift the card Right
				j = j - gap;
			}
			a[j+gap] = key;
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
	insertion_sort(a, n);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
