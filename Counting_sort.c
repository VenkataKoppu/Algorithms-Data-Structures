//Author : Venkat
//Cormen lesson 1 : Counting sort working
//Doesn't work with negative numbers
//Use this when, range of numbers is small,starts from 0 to n and contains lot of duplicates
//can be modified to m - n range also
//Complexity O(n + k) where k is the range of input
//Space Complexity O(n + k)
//stable sort

#include <stdio.h>

int get_max(int a[], int n)
{
	int i;
	int max = a[0];
	for(i = 1; i < n; i++) //Get Max to determine range of numbers
	{
		if(a[i] > max)
			max = a[i];
	}
	return max;
}

void counting_sort(int a[], int n)
{
	int i, j;
	int aux[n]; //Output Array
	int max = get_max(a, n);
	int count[max+1]; //Count Occurrences
	memset(count, 0, sizeof(count));
	for(i = 0; i < n; i++)
	{
		++count[a[i]];
	}
	for(i = 1; i < max+1; i++) //Cumulative count
	{
		count[i] += count[i-1];
	}
	//The modified count array indicates the position of each object in the output sequence
	for(i = n-1; i >= 0; i--) //arrange numbers in output: made from backwards to retain stable nature
	{
		aux[count[a[i]]-1] = a[i];
		--count[a[i]];
	}
    for(i = 0; i < n; i++) //Copy contents to original array
    {
		a[i] = aux[i];
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
	counting_sort(a, n);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
