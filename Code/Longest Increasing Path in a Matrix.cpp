class Solution {
public:
    int dp[200][200];
    int calc(vector<vector<int>>& mat,int i,int j,int t,int n,int m){
        int ans=0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if((i+1)<n && mat[i+1][j]>mat[i][j]){
            ans=max(ans,calc(mat,i+1,j,0,n,m)+1);
        }
        if((i-1)>=0 && mat[i-1][j]>mat[i][j]){
            ans=max(ans,calc(mat,i-1,j,0,n,m)+1);
        }
        if((j+1)<m && mat[i][j+1]>mat[i][j]){
            ans=max(ans,calc(mat,i,j+1,0,n,m)+1);
        }
        if((j-1)>=0 && mat[i][j-1]>mat[i][j]){
            ans=max(ans,calc(mat,i,j-1,0,n,m)+1);
        }
        dp[i][j]=ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         for(int i=0;i<200;i++){
             for(int j=0;j<200;j++){
                 dp[i][j]=-1;
             }
         }
         int n=matrix.size();
         int m=matrix[0].size();
         int ans=0;
        
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,calc(matrix,i,j,0,n,m));
            }
         }
         return ans+1;
    }
};
