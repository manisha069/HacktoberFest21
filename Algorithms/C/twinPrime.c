//twin Primes
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int main()
{
	
	int num;
	int prime;
	printf("Enter a positive Integer: ");
	scanf("%d", &num); //taking input

	while (num < 0)
	{
		printf("Invalid input!\nEnter Positive Integer Again: ");
		scanf("%d", &num);
	}

	for (int i = 3; i < num; i++)
	{
		prime = 0;
		for (int j = 3; j < i; j++)
		{
			if (i % j == 0 || (i + 2) % j == 0)
			{
				prime = 1;
			}
		}
		
		if (prime == 0)
		{
			//printf("Twin prime numbers between 2 and %d are ", num);
			printf("(%d,%d)", i, i + 2);
			printf("\n");
		}
	}








	return 0;
}