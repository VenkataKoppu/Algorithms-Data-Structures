//Author : Venkat
//Cormen Lesson 1 : comb sort working
//Comb Sort is mainly an improvement over Bubble Sort. Comb Sort improves on Bubble Sort by using gap of size more than 1.
//The gap starts with a large value and shrinks by a factor of 1.3 in every iteration until it reaches the value 1.
//Thus Comb Sort removes more than one inversion counts with one swap and performs better than Bubble Sort.
//The shrink factor has been empirically found to be 1.3 (by testing Combsort on over 200,000 random lists) [Source: Wiki]
//Although, it works better than Bubble Sort on average, worst case remains O(n2).

#include <stdio.h>

// To find gap between elements
int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap*10)/13;

    if (gap < 1)
        return 1;
    return gap;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// Function to sort a[0..n-1] using Comb Sort
void comb_sort(int a[], int n)
{
    // Initialize gap
    int gap = n;
    int i;
    // Initialize swapped as true to make sure that loop runs
    int swapped = 1;

    // Keep running while gap is more than 1 and last iteration caused a swap
    while(gap != 1 || swapped == 1)
    {
        // Find next gap
        gap = getNextGap(gap);

        // Initialize swapped as false so that we can check if swap happened or not
        swapped = 0;

        // Compare all elements with current gap
        for(i = 0; i < n-gap; i++)
        {
            if(a[i] > a[i+gap])
            {
                swap(&a[i], &a[i+gap]);
                swapped = 1;
            }
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
	comb_sort(a, n);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
