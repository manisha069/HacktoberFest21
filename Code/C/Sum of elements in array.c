#include<stdio.h>

void arsum(int *a, int n){
    int *b=a,c=0;
    for(int i=0; i<n; i++)
        c+=*b++;
    printf("The sum of the elements in the array is %d\n",c);
}

int main(){
    int n,*p;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int a[n];
    p=a;
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
        scanf("%d",p++);
    arsum(a,n);
    return 0;
}
