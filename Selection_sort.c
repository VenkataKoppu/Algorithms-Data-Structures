//Author : Venkat
//Cormen lesson 1 : Selection sort working
//Time Complexity O(n2) - Descending order and n when already sorted
//Seldom used but a good option if writes is a costly operation: only n writes
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int a[], int n)
{
	int i, j, min_idx, flag = 0;
	for(i = 0; i < n - 1; i++) //Number of Passes
	{
		min_idx = i;
		for(j = i + 1; j < n; j++) //Number of Comparisons To find Min
		{
			if(a[j] < a[min_idx])
			{
				min_idx = j;
				flag = 1;
			}
		}
		if(flag)
        {
            swap(&a[i], &a[min_idx]);
        }
        else
		{
			printf("\nAlready Sorted Array!");
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
	printf("\nEnter Elements:\n");
	for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
	selection_sort(a, n);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
