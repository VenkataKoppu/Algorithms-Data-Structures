//Author : Venkat
//Cormen lesson 1 : Merge sort working
//Time Complexity is always nlog n : but number of comparisons vary: 
//For the worst case: First sort the array: then for each split arrange alternate elements
//Ex: 12345678 -> 1357 2468 -> 15 37 26 48 -> 5 1 7 3 6 2 8 4
//Merge operation of merge sort can be implemented without extra space for linked lists: usually prefered for sorting Linked Lists
//Stable, Out of place, Online: Prefered over quicksort when data is huge and stored in external storage

#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
	int i, j, k; //Pointers to Left, Right and Main Arrays respectively
	int left_size = mid - low + 1; //Since array index starts from 0- +1 
	int right_size = high - (mid + 1) + 1;
	int left[left_size];
	int right[right_size];
	//Copy contents from main array to left and right arrays according to index of splitting them(Generally Middle)
	for(i = 0; i < left_size; i++)
	{
		left[i] = a[low + i];
	}
	for(j = 0; j < right_size; j++)
	{
		right[j] = a[mid + 1 + j];
	}
	//Reset pointers
	i = j = 0;
	k = low;
	//Copy contents from left and right array(split) to main array accordingly by comparing
	while(i < left_size && j < right_size)
	{
		if(left[i] <= right[j])
			a[k++] = left[i++];
		else
			a[k++] = right[j++];
	}
	//Copy the remaining elements if any present in either left or right array
	while(i < left_size)
		a[k++] = left[i++];
	while(j < right_size)
		a[k++] = right[j++];
}

void merge_sort(int a[], int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high)/2;
		merge_sort(a, low, mid); //Recursively split the left part
		merge_sort(a, mid+1, high); //Recursively split the right part
		merge(a, low, mid, high); 
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
	merge_sort(a, 0, n-1);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
