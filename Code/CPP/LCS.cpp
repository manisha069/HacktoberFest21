#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vvi  vector<vector<int> >
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define pi pair<int, int>
#define pl pair<ll, ll>
#define fora(i, a, n) for(ll i = a; i < n; i++)
#define T int tt; cin >> tt; while(tt--)

int dp[1001][1001];
    int helper(string &text1,int i , string &text2,int j){
        if(i==text1.length() || j==text2.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(text1[i]==text2[j])
            return dp[i][j] = 1+helper(text1,i+1,text2,j+1);
        else
            return dp[i][j] = max(helper(text1,i+1,text2,j),helper(text1,i,text2,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return helper(text1,0,text2,0);
    }

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); 

string a,b;
cin>>a>>b;
cout<<longestCommonSubsequence(a,b);

return 0;}
