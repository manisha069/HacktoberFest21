#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<stddef.h>
struct node
{
    int data;
    struct node *next;

}*last=NULL;
main()
{

    int i,choice,n,d,pos,count;
    void create(int);
    void display();
    void search(int);
    void count_list();
while(1)
{

    printf("press 1 to create the list");
    printf("\npress 2 to display the list");
    printf("\npress 3 to search an element in the list:");
    printf("\npress 4 to count elements in the list:");
    printf("\npress 5 to enter the choice:");
    printf("\npress 6 to exit");
    printf("\nEnter the choice:");
    scanf("%d",&choice);
    switch(choice)
    {

        case 1:printf("\nEnter the initial size:");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("\nEnter the initial population:");
                    scanf("%d",&d);
                    create_list(d);

                }
                break;
        case 2:display();
                break;
        case 3:printf("\nEnter the value of searched element:");
                scanf("%d",&d);
                search(d);
                break;

        case 4:count_list();
                break;
        case 5:exit(0);
    }
}
}
void create(int d)
{
    struct node*temp;
    temp=malloc(sizeof(struct node));
    temp->data=d;
    if(last==NULL)
    {
        temp->next=temp;
    }
    else{
        temp->next=last->next;
        last->next=temp;
    }
    last=temp;

}
void display()
{
    struct node *q;
    q=last->next;
    while(q!=last)
    {
        printf("%d",q->data);
        q=q->next;

    }

}
void  search(int num)
{
    struct node *q;
    int count,flag;
    q=last->next;
    count=0;
    flag=0;
    while(q!=last)
    {
        if(q->data==num)
        {

            flag=1;
            break;
        }
        count++;
        q=q->next;
    }
    if(flag==1)
        printf("\ndata is found in index:%d",count);
    else
        printf("\ndata is not found in the list");
}
void count_list()
{
    struct node *q;
    int count;
    q=last->next;
    while(q!=last)
    {
        count++;
    }
    printf("\nthe number of elemements is:",count);
}