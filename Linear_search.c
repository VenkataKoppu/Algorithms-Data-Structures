//Author : Koppu
//Cormen : Implement linear Search

#include <stdio.h>

int linear_search(int a[], int n, int key)
{
	int i;
	for (i = 0; i <= n; i++)
	{
		if(key == a[i])
			return 1;
		else
			continue;
	}
	return 0;
}

int main(void)
{
	int a[20];
	int key, n, i;
	printf("\nEnter Input Size: ");
	scanf("%d",&n);
	printf("\nEnter key: ");
	scanf("%d",&key);
	printf("\nEnter Elements: ");
	for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
	if(linear_search(a, n, key))
	{
		printf("\nItem Found - Search success!");
	}
	else
		printf("\nItem not Found - Search unsuccessful!");
}
