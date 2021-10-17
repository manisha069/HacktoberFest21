#include<stdio.h>
#include<stdlib.h> 

struct term
{
    int coefi;
    int exp;

};

struct poly
{
    int n;
    struct term *t;
};
/*
int evaluetion(p,term)
{
    for ( i = 0; i < p.n; i++)
    {
        store += p.n[i].coefi *p.n[i].exp ; 
    }
    return store;
}
*/


struct poly *addittion (struct poly *p1, struct poly *p2)
{
    int i,j,k;
    struct poly *p3;
    p3=(struct poly*)malloc(sizeof(struct poly));
    p3->t=(struct term *)malloc((p1->n+p2->n)*sizeof(struct term));

    i=j=k=0;

    while(i<p1->n && j<p2->n)
    {
        if (p1->t[i].exp>p2->t[j].exp) 
        {
            p3->t[k++]=p1->t[i++];
        }
        else if (p1->t[i].exp<p2->t[j].exp)  
        {
            p3->t[k++]=p1->t[j++];
        }
        else
        {
            p3->t[k].exp=p2->t[i].exp ;
            p3->t[k++].coefi = p1->t[i++].coefi + p2->t[j++].coefi ;
        }

    }
    for (;i<p1->n;i++)p3->t[k++]=p1->t[i];    
    for (;j<p2->n;j++)p3->t[k++]=p2->t[j];

    p3->n=k;
    return p3;


}


void create(struct poly *p)
{
    int i;
    struct term t;

    printf(" enter the no. of non zero term: ");
    scanf("%d",&p->n);

    //array in heap
    p->t = (struct term*)malloc(p->n*sizeof(struct term));

    printf("ENTER POLYNOMIAL TERM \n ");

    for (i = 0; i < p->n; i++)
    {
        printf("enter %d term no.: " ,i+1);
        scanf("%d%d",&p->t[i].coefi,&p->t[i].exp);
    }
    
    printf("\n");

}

void display(struct poly p)
{
    int i=0;
    for ( i = 0; i < p.n; i++)
    {
        printf("%dx%d+",p.t[i].coefi,p.t[i].exp);

    }
}



int main ()
{
    struct poly p1,p2, *p3;

    create(&p1);
    create(&p2);

    p3=addittion(&p1,&p2);

    printf("\n");
    printf("first polynomial is:\n");
    display(p1);
    printf("\n");
    printf("second polynomial is:\n");
    display(p2);
    printf("\n");
    printf("your addittion of two polynomial is:\n");
    display(*p3);

    return 0;

}