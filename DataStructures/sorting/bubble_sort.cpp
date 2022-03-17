// program to implement bubble sort

#include<stdio.h>
#define MAX 150

int main()
{
   int arr[MAX];
   int temp,i,j,size;

   printf("Enter size of array : ");
   scanf("%d",&size);

    printf("Enter %d elements\n", size);
	for(i=0; i<size; i++)
	{
		scanf("%d", &arr[i]);
	}

   for(i=0; i<size-1; i++)
	{
		for(j=0; j<size-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

    printf("\nAfter applying bubble sort sorted elements are : \n");
	for(i=0; i<size; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}
