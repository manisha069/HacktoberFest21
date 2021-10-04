#include <stdio.h>
#include <stdlib.h>
int main()
{
    int Max[10][10], need[10][10], allocation[10][10], available[10], completed[10], safeSequence[10];
    int p, r, i, j, process, count;
    count = 0;

    printf("Enter total number of Process : ");
    scanf("%d", &p);

    for(i = 0; i< p; i++)
        completed[i] = 0;               //  flag whether the process completed or not

    printf("\n\nEnter total number of resources : ");
    scanf("%d", &r);

    printf("\n\nEnter the Maximum Matrix for each process : ");
    for(i = 0; i < p; i++)
    {
        printf("\nFor process %d : ", i + 1);
        for(j = 0; j < r; j++)
            scanf("%d", &Max[i][j]);
    }

    printf("\n\nEnter the allocation for each process : ");
    for(i = 0; i < p; i++)
    {
        printf("\nFor process %d : ",i + 1);
        for(j = 0; j < r; j++)
            scanf("%d", &allocation[i][j]);
    }

    printf("\n\nEnter the Current Available Resources with OS : ");
    for(i = 0; i < r; i++)
        scanf("%d", &available[i]);

    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
        {
            need[i][j] = Max[i][j] - allocation[i][j];
        }

        do
        {
            printf("\nMaximum matrix:\t Allocation matrix:\n");

            for(i = 0; i < p; i++)
            {
                for( j = 0; j < r; j++)
                    printf("%d ", Max[i][j]);

                printf("\t\t");

                for( j = 0; j < r; j++)
                    printf("%d ", allocation[i][j]);

                printf("\n");
            }

            process = -1;           // For Each loop eligible process variable set = -1

            for(i = 0; i < p; i++)
            {
                if(completed[i] == 0)   //if not completed
                {
                    process = i ;       // Process Value updated
                    for(j = 0; j < r; j++)
                    {
                        if(available[j] <= need[i][j])       // for each Resource of need matrix availability checked
                        {
                            process = -1; //  if one of resource is having higher value then RESET default value
                            break;
                        }
                    }
                }
                if(process != -1)
                    break;
            }

            if(process != -1)
            {
                printf("\nProcess %d runs to completion!", process + 1);
                safeSequence[count] = process + 1;
                count++;                            // increment count of completed process
                for(j = 0; j < r; j++)
                {
                    available[j] += allocation[process][j];
                    allocation[process][j] = 0;         // allocation turned to zero
                    Max[process][j] = 0;
                    completed[process] = 1;             // mark completed process
                }
            }
        }
        while(count != p && process != -1);

        if(count == p)
        {
            printf("\nThe system is in a safe state !!\n");
            printf("\n");
            printf("\nSafe Sequence : < ");
            for( i = 0; i < p; i++)
                printf("%d ", safeSequence[i]);
            printf(">\n");
        }
        else
            printf("\nThe system is in an unsafe state !!");

}