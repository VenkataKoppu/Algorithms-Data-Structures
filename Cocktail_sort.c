//Author : Venkat
//Cormen Lesson 1 : cocktail sort working
//Cocktail Sort is a variation of Bubble sort. Cocktail performs better than Bubble Sort
//Time-Complexity: O(n2)
//Stable, Inplace
#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void cocktail_sort(int a[], int n)
{
	int i;
	int start = 0, end = n - 1;
	int flag = 1; //To Check if List is already sorted - Best case of O(n)
	while(flag)//Until there is a swap: no swaps indicate sorted array
	{
		flag = 0;
		for(i = start ; i < end; i++) //Number of Comparisons for each Pass: n-1: This sinks the max value to the bottom
		{
			if(a[i] > a[i+1])
			{
                swap(&a[i], &a[i+1]);
				flag = 1;
			}
		}
		end--;
		if(flag == 0)
		{
			break;
		}
		flag = 0;
		for(i = end ; i > start; i--) //Number of Comparisons for each Pass: This floats the min value to the top
		{
			if(a[i] < a[i-1])
			{
                swap(&a[i], &a[i-1]);
                flag = 1;
			}
		}
		start++;
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
	cocktail_sort(a, n);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
