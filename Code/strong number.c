#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int r;
    int sum=0;
    scanf("%d",&n);
    int t;
    t=n;
    while(t>0)
    {
        int temp;
        int fact=1;

        r= t%10;
        temp=r;
        while(temp>0)
        {
          fact=temp*fact;
          temp--;

        }

        sum=sum+fact;
        fact=1;
        t=t/10;

    }
    if(sum==n)
    {
        printf("Strong Number");
    }
    else{
        printf("Not a Strong Number");
    }
}
