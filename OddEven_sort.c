//Author : Venkat
//Cormen Lesson 1 : Odd-Even sort working
//This is basically a variation of bubble-sort. This algorithm is divided into two phases- Odd and Even Phase.
//In the odd phase, we perform a bubble sort on odd indexed elements and in the even phase, we perform a bubble sort on even indexed elements.
//Time Complexity : O(N2) 

#include <stdio.h>
 
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
} 
 
void oddEven_sort(int arr[], int n)
{
    int isSorted = 1; // Initially array is unsorted
	int i;
    while(isSorted)
    {
        isSorted = 0;
 
        // Perform Bubble sort on odd indexed element
        
		for(i = 1; i < n-1; i += 2)
        {
            if(arr[i] > arr[i+1])
            {
                swap(&arr[i], &arr[i+1]);
                isSorted = 1;
            }
        }
 
        // Perform Bubble sort on even indexed element
        for(i = 0; i < n-1; i += 2)
        {
            if (arr[i] > arr[i+1])
            {
                swap(&arr[i], &arr[i+1]);
                isSorted = 1;
            }
        }
    }
 
    return;
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
	oddEven_sort(a, n);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
