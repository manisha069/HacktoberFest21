// Program to implement insertion sort

#include<stdio.h>
#define MAX 100

int main()
{
    int arr[MAX];
    int i,j,size,temp,pivot;

    printf("Enter size of array : ");
    scanf("%d",&size);

    printf("Enter %d elements\n", size);
	for(i=0; i<size; i++)
	{
		scanf("%d", &arr[i]);
	}

	for(i=0;i<size;i++)
    {
        pivot = arr[i];
        for(j=i-1;j>=0&&arr[j]>pivot;j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = pivot;
    }

    printf("\nAfter applying insertion sort, sorted elements are : \n");
    for(i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
}
