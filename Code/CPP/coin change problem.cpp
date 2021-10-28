#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int help(int denominations[], int numDenominations, int value, int** output)
{
     if(numDenominations == 0)
       return 0;
    if(value == 0)
        return 1;
    if(value < 0)
        return 0;
    if(output[numDenominations][value] != -1)
        return output[numDenominations][value];
    
    int first = help(denominations,numDenominations,value - denominations[0], output);
    int second = help(denominations + 1,numDenominations - 1,value, output);
    output[numDenominations][value] = first + second;
    return (first+second);
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    
    int** output = new int*[numDenominations+1];
    for(int i = 0; i <= numDenominations; i++)
    {
        output[i] = new int[value+1];
        for(int j = 0; j <= value; j++)
        {
            output[i][j] = -1;
        }
    }
    
    return help(denominations, numDenominations, value, output);
/*
int output[numDenominations + 1][value + 1] = {-1};
    return help(denominations, numDenominations, value, output);*/
  
}