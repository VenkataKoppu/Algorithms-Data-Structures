//Author : Venkat
//Cormen Lesson 1 : Bubble sort working
//Time complexity O(n2): Used only for educational purposes
//Also called sinking sort since for every pass the largest value is send to the bottom(last index)
//Inplace and stable algorithm

#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int a[], int n)
{
	int i, j;
	int flag = 0; //To Check if List is already sorted - Best case of O(n): Optimized Bubble Sort
	for(i = 0; i < n-1; i++) //Number of Passes
	{
		for(j = 0 ; j < n-i-1; j++) //Number of Comparisons for each Pass
		{
			if(a[j] > a[j+1])
			{
                swap(&a[j], &a[j+1]);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			printf("Already Sorted List");
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
	bubble_sort(a, n);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
