//Author : Venkat
//Cormen lesson 1 : gnome sort working
//Gnome Sort also called Stupid sort is based on the concept of a Garden Gnome sorting his flower pots.
//A garden gnome sorts the flower pots by the following method- He looks at the flower pot next to him(His current position) and the previous one;
/*-if they are in the right order he steps one pot forward, otherwise he swaps them and steps one pot backwards.
  -If there is no previous pot (he is at the starting of the pot line), he steps forwards;
  -if there is no pot next to him (he is at the end of the pot line), he is done.
*/
//Time Complexity – As there are no nested loop (only one while) it may seem that this is a linear O(N) time algorithm. But the time complexity is O(N^2).
//This is because the variable – ‘index’ in our program doesn’t always gets incremented, it gets decremented too.
//However this sorting algorithm is adaptive and performs better if the array is already/partially sorted.

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
	*a = *b;
	*b = temp;
}

void gnome_sort(int a[], int n)
{
    int index = 0;

    while (index < n)
    {
        if (index == 0)
            index++;
        if (a[index] >= a[index-1])
            index++;
        else
        {
            swap(&a[index], &a[index-1]);
            index--;
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
	printf("\nEnter Elements\n");
	for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
	gnome_sort(a, n);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
