//Author : Venkat
//Cormen lesson 1 : Calculate number of inversions
//Time Complexity is: nlog n
 
/*Suppose we know the number of inversions in the left half and right half of the array (let be inv1 and inv2), what kinds of inversions are not 
accounted for in Inv1 + Inv2? The answer is – the inversions we have to count during the merge step. Therefore, to get number of inversions, we 
need to add number of inversions in left subarray, right subarray and merge().
How to get number of inversions in merge()?
In merge process, let i is used for indexing left sub-array and j for right sub-array. At any step in merge(), if a[i] is greater than a[j], 
then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) 
will be greater than a[j]
*/

#include <stdio.h>

int merge(int a[], int low, int mid, int high)
{
	int i, j, k; //Pointers to Left, Right and Main Arrays respectively
	int left_size = mid - low + 1; //Since array index starts from 0- +1
	int right_size = high - (mid + 1) + 1;
	int left[left_size];
	int right[right_size];
	int inversions = 0;
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
        {
			a[k++] = right[j++];
			inversions += left_size - i;
        }
	}
	//Copy the remaining elements if any present in either left or right array
	while(i < left_size)
		a[k++] = left[i++];
	while(j < right_size)
		a[k++] = right[j++];

	return inversions;
}

int merge_sort(int a[], int low, int high)
{
	int mid;
	int inversions = 0;
	if(low < high)
	{
		mid = (low + high)/2;
		inversions = merge_sort(a, low, mid); //Recursively split the left part
		inversions += merge_sort(a, mid+1, high); //Recursively split the right part
		inversions += merge(a, low, mid, high);
	}
	return inversions;
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
	printf("\nInversion Count: %d", merge_sort(a, 0, n-1));
    return 0;
}
