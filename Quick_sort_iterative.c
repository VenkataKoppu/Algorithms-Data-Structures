//Author : Venkat
//Cormen lesson 1 : Iterative Quick sort working

#include <stdio.h>

void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

/* This function is same in both iterative and recursive*/
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

void quickSortIterative(int a[], int low, int high)
{
    // Create an auxiliary stack
    int stack[high - low + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of low and high to stack
    stack[++top] = low;
    stack[++top] = high;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop high and low
        high = stack[top--];
        low = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int pivot = partition(a, low, high);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (pivot-1 > low)
        {
            stack[++top] = low;
            stack[++top] = pivot - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if(pivot+1 < high)
        {
            stack[++top] = pivot + 1;
            stack[++top] = high;
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
	quickSortIterative(a, 0, n-1);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
