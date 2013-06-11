#include "stdlib.h"

#if 0
char a[] = {5, 3, 3, 4, 3};

void main()
{
	int i,j;
	int a1[5],a2[5];
	int sum = 0;

	/* Sort given numbers in descending order */
	for(i = 0; i < 5; i ++)
	{
		for (j = i + 1; j < 5; j ++)
		{
			if (a[i] < a[j])
			{
				a[i] = a[i] + a[j];
				a[j] = a[i] - a[j];
				a[i] = a[i] - a[j];
			}
		}
	}
	/* Numbers are in descending order */
	for(i = 0; i < 5; i ++) {
		printf("%d->", a[i]);
		sum += a[i];
	}
	printf("\n");
	if (sum%2 == 0)
		printf("Partition is possible\n");
	else
		printf("Partition is not possible\n");
}
#endif


char* partition(int arr[])
{
 int n, i, sum;
 i = sizeof(arr)/sizeof(arr[0]);
 for (i = 0; i < n; i++)
       sum += arr[i];
 
    // If sum is odd, there cannot be two subsets with equal sum
    if (sum%2 != 0)
       return "No";
    else
       return "yes";
}

void main()
{
	int arr[] = {1,5,3};
	char *p;
	p = partition(arr);
	printf("%s", p);
}


