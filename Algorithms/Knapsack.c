/* Knapsack Problem using Greedy Method */
#include<stdio.h>

void Knapsack(int n, float w[], float p[], float m);
void LargestProfit(int n, float w[], float p[], float m);
void SmallestWeight(int n, float w[], float p[], float m);

int main()
{
	float w[20], p[20], ratio[20], m;
	//p-profit, w-weights, x-ratio, m-capacity, n-num
	int i, j,n;
	float temp;
	
	printf("\nEnter the number of objects: ");
	scanf("%d", &n);
	printf("\nEnter the details: ");
	
	for(i=0;i<n;i++)
	{
		printf("\nItem %d:", i+1);	
		printf("\n\tWeight: ");
		scanf("%f", &w[i]);	
		printf("\tProfit: ");
		scanf("%f", &p[i]);
	}	
	printf("\nEnter the capacity of Knapsack: ");
	scanf("%f", &m);
	
	for(i=0;i<n;i++)
	{
		ratio[i]=p[i]/w[i];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ratio[i] < ratio[j])
			{
				temp = ratio[j];
				ratio[j] = ratio[i];
				ratio[i] = temp;
				
				temp = w[j];
				w[j] = w[i];
				w[i] = temp;
				
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			}
		}
	}

	printf("\nLargest Ratio of Profit by Weight Strategy:\n");
	Knapsack(n, w, p, m);
	printf("\n\nLargest Profit Strategy:\n");
	LargestProfit(n, w, p, m);
	printf("\n\nSmallest Weight Strategy:\n");
	SmallestWeight(n, w, p, m);

 	return 0;
}



//-------CALCULATE FRACTION OF WEIGHTS AND PROFIT-------

void Knapsack(int n, float w[], float p[], float m)
{
	float x[20], profit;
	int i, j;
	float u;
	u=m;
	profit=0.0;
	
	for(i=0;i<n;i++)
	x[i]=0.0;
	for(i=0;i<n;i++)
	{
		if(w[i] > u)
		break;
		else
		{	
			x[i]=1.0;
			u=u-w[i];
			profit=profit+p[i];	
		}
	}

 	if(i<n)
	x[i]=u/w[i];

 	profit=profit + ( x[i] * p[i] );

	printf("\n\tThe resultant vector is ");

 	for(i=0;i<n;i++)
		printf("%.2f\t", x[i]);

	printf("\n\n\tThe total profit is %.3f", profit);
}

//-------LARGEST PROFIT STRATEGY-------
void LargestProfit(int n, float w[], float p[], float m)
{

 	int i, j;
	float temp;
	float ratio[20];
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i] < p[j])
			{	
				temp = ratio[j];
				ratio[j] = ratio[i];	
				ratio[i] = temp;
				
				temp = w[j];
				w[j] = w[i];
				w[i] = temp;
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			}
		}
	}
	Knapsack(n, w, p, m);
}

//-------SMALLEST WEIGHT STRATEGY-------
void SmallestWeight(int n, float w[], float p[], float m)
{
	int i, j;
	float temp;
	float ratio[20];
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(w[i] > w[j])
			{	
				temp = ratio[j];
				ratio[j] = ratio[i];
				ratio[i] = temp;
				
				temp = w[j];
				w[j] = w[i];
				w[i] = temp;
				
				temp = p[j];	
				p[j] = p[i];	
				p[i] = temp;
			}
		}	
	}
	Knapsack(n, w, p, m);
}
