//Program to compute factorial of a number using recursion.
# include<stdio.h>

int fact(int);

int main()
{
    int num, result;
    printf("Enter a positive integer : \n");
    scanf("%d", &num);
    
    if(num < 0)
    {
        printf("Invalid positive integer. Please try again with positive integer.");
        return 0;
    }
    
    result = fact(num);
    printf("The factorial of %d is %d.", num, result);
    return 0;
}

int fact(int n)
{
    if(n==0)
        return 1;
        
    if(n==1)
        return(n);
    else
        return(n*fact(n-1));
}