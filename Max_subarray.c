//Author: Koppu
//Description: Max-subarray Problem
/*
Simple idea of the Kadane's algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). 
And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this). Each time we get a positive 
sum compare it with max_so_far and update max_so_far if it is greater than max_so_far
Time Complexity: O(n)
Algorithmic Paradigm: Dynamic Programming
*/

#include <stdio.h>

int max_subarray(int a[], int n)
{
	int max_so_far = 0, max_ending_here = 0;
	int i;
	int flag = 0;
	int start_index = 0;
	int end_index = 0;
	for (i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if ((max_so_far < max_ending_here) && (flag == 1))
		{
            max_so_far = max_ending_here;
			end_index = i + 1;
		}
        if ((max_so_far < max_ending_here) && (flag == 0))
		{
            max_so_far = max_ending_here;
			start_index = end_index = i + 1;
			flag = 1;
		}
    }
    if(flag == 0)
	{
		max_so_far = a[0];
		for(i = 0; i < n; i++)
		{
			if(a[i] > max_so_far)
			{
				max_so_far = a[i];
				start_index = end_index = i + 1;
			}
		}
	}
	printf("\nStart Index: %d End Index: %d", start_index, end_index);
    return max_so_far;
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
	printf("\nMax Sub-Array sum is: %d", max_subarray(a, n));
	return 0;
}
