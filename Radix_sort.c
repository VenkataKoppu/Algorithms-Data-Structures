//Author : Venkat
//Cormen lesson 1 : Radix sort working: digit by digit sorting starting from least significant digit to most significant digit
//Doesn't work with negative numbers,Use this when, range of numbers is n squared thus making counting sort n2 complexity

/*Complexity
Let there be d digits in input integers. O(d*(n+b)) time, b is the base for representing numbers,decimal system, b is 10.
If k is the maximum possible value, then d would be O(logb(k)). So overall time complexity is O((n+b) * log b(k)).
Which looks more than the time complexity of comparison based sorting algorithms for a large k.
Let us first limit k. Let k <= nc where c is a constant. In that case, the complexity becomes O(nLogb(n)).
But it still doesn’t beat comparison based sorting algorithms.
What if we make value of b larger?. What should be the value of b to make the time complexity linear?
If we set b as n, we get the time complexity as O(n).
We can sort array of integers with range from 1 to nc if the numbers are represented in base n
(or every digit takes log2(n) bits).*/

/*Usage
Is Radix Sort preferable to Comparison based sorting algorithms like Quick-Sort?
If we have log2n bits for every digit, the running time of Radix appears to be better than Quick Sort for a wide range
of input numbers. The constant factors hidden in asymptotic notation are higher for Radix Sort and Quick-Sort
uses hardware caches more effectively. Also, Radix sort uses counting sort as a subroutine and counting sort takes extra
space to sort numbers.
*/

#include <stdio.h>
#include <string.h>

int get_max(int a[], int n)
{
	int i;
	int max = a[0];
	for(i = 1; i < n; i++) //Get Max to determine number of digits
	{
		if(a[i] > max)
			max = a[i];
	}
	return max;
}

void counting_sort(int a[], int n, int exp)
{
	int i, j;
	int aux[n]; //Output Array
	int count[10]; //Mod 10 to get least significant digit 0 - 9
	memset(count, 0, sizeof(count));
	for(i = 0; i < n; i++)
	{
		++count[(a[i]/exp)%10];
	}
	for(i = 1; i < 10; i++) //Cumulative count
	{
		count[i] += count[i-1];
	}
	for(i = n-1; i >= 0; i--) //Arrange numbers in output
	{
		aux[count[(a[i]/exp)%10]-1] = a[i];
		--count[(a[i]/exp)%10];
	}
    for(i = 0; i < n; i++) //Copy contents to original array
    {
		a[i] = aux[i];
    }
}
// digit by digit sorting
void radix_sort(int a[], int n)
{
	int exp;
	int max = get_max(a, n);
	for(exp = 1; max/exp > 0; exp *= 10)
	{
		counting_sort(a, n, exp);
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
	radix_sort(a, n);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
