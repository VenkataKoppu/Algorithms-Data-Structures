//Author : Venkat
//C program to sort an array with 0,1 and 2 in a single pass using Dutch national flag algorithm

#include<stdio.h>

/* Function to swap *a and *b */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sort the input array, the array is assumed to have values in {0, 1, 2}
void sort(int a[], int size)
{
    int low = 0;
    int high = size;
    int mid = 0;

    while (mid <= high)
    {
        switch (a[mid])
        {
        case 0:
            swap(&a[low++], &a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(&a[mid], &a[high--]);
            break;
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
	sort(a, n-1);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
