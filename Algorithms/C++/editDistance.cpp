// Edit distance is the minimum number of deletions, updations and insertions required to convert one string to another
// the time complexity is O(n*m) where n is the lenght of the longer string and m is the length of shorter string
// the space complexity is O(m) where m is the lenght of the shorter string 

#include <iostream>
#include <vector>

using namespace std;

int editDistance(string X, string Y)
{
    int n=X.size(), m=Y.size();

    if(n<m)
    return editDistance(Y, X); //to ensure that Y is the smaller string

    vector<vector<int>> dp(2, vector<int>(m+1));

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0)
            {
                dp[0][j]=j;
            }
            else if(j==0)
            {
                dp[i%2][0]=i;
            }
            else
            {
                if(X[i-1]==Y[j-1])
                {
                    dp[i%2][j]=dp[(i-1)%2][j-1];
                }
                else
                {
                    dp[i%2][j]=min(dp[(i-1)%2][j], min(dp[i%2][j-1], dp[(i-1)%2][j-1]))+1;
                }
            }
        }
    }
    return dp[n%2][m];
}

int main()
{
    string X, Y;
    cin>>X>>Y;
    cout<<editDistance(X,Y)<<"\n";
}