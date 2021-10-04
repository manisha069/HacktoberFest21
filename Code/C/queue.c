#include<stdio.h>
#define MAX 10

int ENQUEUE(int [], int);
int DEQUEUE(int [], int, int);
void DISPLAY(int [],int ,int);

int main()
{
 int Q[MAX], F = -1, R = -1,ch=1;
  do{
    printf("Enter choice: \n1. for ENQUEUE \n2. for DEQUEUE \n3. for DISPLAY \n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
            R = ENQUEUE(Q,R);
            if(R == 0)
            {
                F = 0;
            }
            break;
        case 2:
            F = DEQUEUE(Q, F, R);
            if(F == -1)
                R = -1;
            break;
        case 3:
            DISPLAY(Q, F, R);
            break;
        default:
                printf("Invalid Choice\n");
                break;

    }
 }while(ch <=3);
 return 0;
}

int ENQUEUE(int Q[], int R)
{
    int x;
    if(R == MAX-1)
        printf("Queue is full \n");
    else
    {
        printf("Enter the element: \n");
        scanf("%d",&x);
        R++;
        Q[R] = x;
        printf("Element added to queue \n");
    }
    return R;
}

int DEQUEUE(int Q[], int F, int R)
{
    if(F == -1)
        printf("Queue is empty \n");
    else if(F == R)
    {
        printf("Dequed element is %d\n",Q[F]);
        F = -1;
    }
    else 
    {
        printf("Dequed element is %d\n",Q[F]);
        F++;
    }
    return F;
}

void DISPLAY(int Q[], int F, int R)
{
    if(F == -1)
        printf("Queue is empty\n");
    else
    {
        for(;F<=R;F++)
            printf("%d\n",Q[F]);
    }
}