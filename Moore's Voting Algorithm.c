//Author: Koppu
//Description: Moore’s Voting Algorithm to find the majority occuring element(> n/2) in linear time O(n)
/*
This is a two step process.

1. Get an element occurring most of the time in the array. This phase will make sure that if there is a majority element then it will return that only.
2. Check if the element obtained from above step is majority element.
*/

#include <stdio.h>

int majority_element(int a[], int n)
{
	int count = 1;
	int i;
	int max_candidate = a[0];
	for(i = 1; i < n; i++)
	{
		//reset count and check for next element
		if(count == 0)
		{
			max_candidate = a[i];
			count = 1;
		}
		else
		{
			if(max_candidate == a[i])
				count++;
			else
				count--;
		}
	}
	count = 0;
	//check if it is really the max
	for(i = 0; i < n; i++)
	{
		if(max_candidate == a[i])
			count++;
	}
	if(count > n/2)
	{
		return max_candidate;
	}
	else
		return 0;
}

int main(void)
{
	int i, n, res;
	printf("Enter Input Size: ");
	scanf("%d", &n);
	int a[n];
	printf("\nEnter Array Elements: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	res = majority_element(a, n);
	if(!res)
		printf("No Majority Element!\n");
	else
		printf("Max Candidate is: %d\n", res);

	return 0;
}
