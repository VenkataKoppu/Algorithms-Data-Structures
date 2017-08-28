//Author : Venkat
//Cormen Lesson 1 : Bogus sort working
//BogoSort also known as permutation sort, stupid sort, slow sort, shotgun sort or monkey sort based on generate and test paradigm. 
//The algorithm successively generates permutations of its input until it finds one that is sorted.
//Time-complexity O(infinity) Average : O(n!)

#include <stdio.h>
#include <time.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
 
// To check if array is sorted or not
int check_sorted(int a[], int n)
{
    int i;
	for(i = 0; i < n-1; i++) {
		if(a[i] > a[i+1])
			return 0;
	}
	return 1;
}
 
// To generate permuatation of the array
void shuffle(int a[], int n)
{
    int i;
	srand(time(NULL));
	for (i = 0; i < n; i++)
        swap(&a[i], &a[rand()%n]);
}
 
void permutation_sort(int a[], int n)
{
    // if array is not sorted then shuffle the array again
    while(!check_sorted(a, n)) {
		shuffle(a, n);
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
	permutation_sort(a, n);
	printf("\nSorted List is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d ",a[i]);
    }
    return 0;
}
