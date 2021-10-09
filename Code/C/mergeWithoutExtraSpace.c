//Merge two sorted arrays (ascending order) without using any extra space
//Explanation - https://www.youtube.com/watch?v=NWMcj5QFW74

#include <stdio.h>
#include <stdlib.h>

void merge(int arr1[], int m, int arr2[], int n)
{
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        int j;
        int last = arr1[m - 1];
        for (j = m - 2; j >= 0 && arr2[i] < arr1[j]; j--)
        {
            arr1[j + 1] = arr1[j];
        }
        if (j != m - 2 || last > arr2[i])
        {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
    }
    for (i = 0; i < m; i++)
    {
        printf(" %d ", arr1[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf(" %d ", arr2[i]);
    }
}
int main()
{
    int arr1[] = {1, 5, 9, 10, 15, 20}; //len = 6
    int arr2[] = {2, 3, 8, 13};         //len = 4
    merge(arr1, 6, arr2, 4);
    return 0;
}
