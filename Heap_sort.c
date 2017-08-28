//Author : Venkat
//Cormen lesson 1 : Heap sort working
//Complexity: nlogn : usually quick sort is much preferred over heapsort : but the binary heap data structure has many uses
//Priority queues in scheduling, binomoial Heap and Fibonacci Heap are variations of Binary Heap. 
//These variations perform union also in O(logn) time which is a O(n) operation in Binary Heap. 
//Heap Implemented priority queues are used in Graph algorithms like Prim’s Algorithm and Dijkstra’s algorithm.
//The Heap data structure can be used to efficiently find the kth smallest (or largest) element in an array. - nlog k
//In-place, typical implementation is not stable
//Any unstable algorithm can be made stable by adding extra comparision w.r.t the positions.

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int a[], int i, int heap_size) //Complexity is log n
{
	int largest = i;
	int left_child = 2*i + 1;
	int right_child = 2*i + 2;
	if(left_child <= heap_size && a[left_child] > a[i])
		largest = left_child;
	if(right_child <= heap_size && a[right_child] > a[largest])
		largest = right_child;
	if(largest != i) //inspect if exchange took place for the need to check heap property is maintained
	{
		swap(&a[i], &a[largest]);
		max_heapify(a, largest, heap_size); //recursively check heap property 
	}
}

void build_max_heap(int a[], int heap_size) //Complexity is n -> refer cormen : Harmonic progression
{
	int i; // Here (heap_size -1)/2 is to get the highest non leaf node to check the heap property 
	for(i = (heap_size - 1)/2; i >= 0; i--) //Given input array is suitably arranged to follow maxheap property 
	{
		max_heapify(a, i, heap_size);
	}
}

void heap_sort(int a[], int heap_size) //complexity nlogn
{
	int i;
	build_max_heap(a, heap_size); //Rearranges the input array to follow heap property
	for(i = heap_size; i >= 0; i--) 
	{
		swap(&a[0], &a[heap_size]); //swap the last element with the first and then apply max heapify
		heap_size--; //the max element is bottomed out: put in the last index
		max_heapify(a, 0, heap_size);
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
	heap_sort(a, n-1);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
