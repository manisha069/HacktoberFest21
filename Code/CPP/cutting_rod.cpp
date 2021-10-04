/*
Question
Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces. */

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>price){
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int sum=INT_MIN;
        for(int j=0;j<i;j++)
        sum=max(sum,price[j]+dp[i-j-1]);
        dp[i]=sum;
    }
    return dp[n];
}
int main() {
	int n;
	cin>>n;
	vector<int>price(n);
	for(int i=0;i<n;i++)
	cin>>price[i];
	 
	cout<<solve(n,price); 
	return 0;
}

