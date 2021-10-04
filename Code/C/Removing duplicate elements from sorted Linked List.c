// Program to remove duplicates from a sorted Linked List.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create (int A[], int n)
{
	int i; 
	struct Node *t, *last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(i=1; i<n; i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p=p->next;
	}
}

void RemoveDuplicate(struct Node *p)
{
	struct Node *q=p->next;
	while(q!=NULL)
	{
		if(p->data != q->data)
		{
			p=q;
			q=q->next;
		}
		else
		{
			p->next=q->next;
			free(q);
			q=p->next;
		}
	}
}

int main()
{
	int A[]={10, 10, 30, 30, 50};
	create(A, 5);
	RemoveDuplicate(first);
	Display(first);
	printf("\n\n");
	return 0;
}


/*

Output :- 

10 30 50

*/
