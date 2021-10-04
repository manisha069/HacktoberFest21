//
//  main.c
//  Lab-5-4
//
//  Created by Aaron R on 26/09/21.
//  The Josephus Problem (or Josephus permutation) is a theoretical problem. Following is the problem statement: There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

#include <stdio.h>
#include <stdlib.h>
 
int josephus(int n, int kill)
{
    int remainder = 0;
    for (int i = 1; i <= n; i++)
        remainder = (remainder + kill) % i;
    return remainder + 1;
}
 
int main()
{
    // Inputting data
    int n;
    scanf("%d",&n);
    int people[100];
    for (int i = 0; i < n ; i++)
        scanf("%d",&people[i]);
    
    // Deciding which position
    int k;
    scanf("%d",&k);
    printf("%d",people[josephus(n,k)-1]);
    return 0;
}

