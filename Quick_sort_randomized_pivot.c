//Author : Venkat
//Cormen lesson 1 : Randomized Quick sort working
//Practical Implementation to escape worst case: This fails to when there are many duplicate elements

#include <stdio.h>
#include <time.h>

void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

int partition(int a[], int low, int high)
{
	int j;
	srand(time(NULL));
	int pivot_index = low + rand() % (high - low + 1);
	printf("Random Index: %d \n", pivot_index);
	int pivot = a[pivot_index];
	swap(&a[high], &a[pivot_index]);
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
		pivot = partition(a, low, high);
		quick_sort(a, low, pivot - 1);
		quick_sort(a, pivot + 1, high);
	}
}

int main(void)
{
	int n, i;
	printf("\nEnter Input Size: ");
	scanf("%d", &n);
	int a[n];
	printf("\nEnter Elements\n");
	for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
	quick_sort(a, 0, n-1);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    return 0;
}
